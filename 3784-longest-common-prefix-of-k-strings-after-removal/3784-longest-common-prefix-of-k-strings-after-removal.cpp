class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        int n = words.size();
        vector<int> ans(n, 0);
        
        int mxLen = 0;
        map<string, int> mp;
        for(int i = 0; i < n; i++){
            mxLen = max(mxLen, (int)words[i].length());
            string pref = "";
            for(int j = 0; j < words[i].length(); j++){
                pref += words[i][j];
                mp[pref]++;
            }
        }
        
        vector<string> mxFreqStr(mxLen + 1, "");
        vector<int> mxFreq(mxLen + 1, 0), secMx(mxLen + 1, 0);
        
        for(auto& [str, freq] : mp){
            int len = str.size();
            
            if(freq > mxFreq[len]){
                secMx[len] = mxFreq[len];
                mxFreqStr[len] = str;
                mxFreq[len] = freq;
            } else if (freq > secMx[len]) secMx[len] = freq;
        }
        
        for(int i = 0; i < n; i++){
            string curr = words[i];
            int lo = 0, hi = mxLen + 1;
            while(lo + 1 < hi){
                int mid = (lo + hi)>>1;
                int freq = 0;
                if(mid <= curr.size() && curr.substr(0, mid) == mxFreqStr[mid]){
                    freq = max(mxFreq[mid] - 1, secMx[mid]);
                } else freq = mxFreq[mid];
                
                if(freq < k) hi = mid;
                else lo = mid;
            }
            ans[i] = lo;
        }
    
        return ans;
    }
};