class Solution {
public:
    string commonPrefix(string s1,string s2){
        int n = s1.size();
        int m = s2.size();
        int i = 0;

        string lcp="";
        while(i < n && i < m && s1[i] == s2[i]){
            lcp+=s1[i];
            i++;
        }

        return lcp;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string lcp = strs[0];

        for(int i = 1; i < n; i++){
            lcp = commonPrefix(strs[i],lcp);
        }

        return lcp;
    }
};