class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1 != n2)
            return false;
        unordered_set<char> se;
        unordered_map<char,char> mapi;
        for(int i = 0; i < n1; i++){
            if(mapi.find(s[i]) == mapi.end()){
                mapi.insert({s[i],t[i]});
                if(se.find(t[i]) == se.end())
                    se.insert(t[i]);
                else 
                    return false;
            }
            else 
                if(mapi[s[i]] != t[i])
                    return false;
        }
        return true;
    }
};