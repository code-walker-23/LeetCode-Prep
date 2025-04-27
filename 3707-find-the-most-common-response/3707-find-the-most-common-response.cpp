class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string, int> m;
        
        for (auto& v : responses) {
            set<string> uniqueResponses(v.begin(), v.end()); 
            for (auto& s : uniqueResponses) {
                m[s]++;
            }
        }
        
        int maxCount = 0;
        string ans = "";

        for (auto& p : m) {
            if (p.second > maxCount){
                maxCount = p.second;
                ans = p.first;
            }
        }
        
        return ans;
    }
};
