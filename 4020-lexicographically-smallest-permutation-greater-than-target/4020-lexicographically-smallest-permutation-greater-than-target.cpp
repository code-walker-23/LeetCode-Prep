class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.size();
        string ans = "";
        sort(s.begin(), s.end());
        
        for (int i = 0; i < n; i++) {
            auto p = lower_bound(s.begin(), s.end(), target[i]);
            if (p != s.end()) {
                if(target[i] < (*p)){
                    target[i] = *p;
                    s.erase(p);
                    sort(s.begin(), s.end());
                    ans = target.substr(0, i + 1) + s;
                    return ans;
                }else{
                     s.erase(p);
                }
            }
            else{
                 if(i == 0)return "";
                 else {
                    int k = i-1;
                    while(k >= 0){
                        s.push_back(target[k]);
                        sort(s.begin(),s.end());
                        auto u = upper_bound(s.begin(),s.end(),target[k]);
                        if(u != s.end()){
                            target[k] = *u;
                            s.erase(u);
                            sort(s.begin(), s.end());
                            ans = target.substr(0, k + 1) + s;
                            return ans;
                        }
                        k--;
                    }
                    return "";
                 }
            }
        }
        if(s.size() == 0){
            bool hasNext = next_permutation(target.begin(),target.end());
            if(hasNext)return target;
            return "";
        }
        return ans;
    }
};