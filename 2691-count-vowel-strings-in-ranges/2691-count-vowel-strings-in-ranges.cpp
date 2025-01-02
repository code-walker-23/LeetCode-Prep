class Solution {
public:
    bool isVowel(char ch){
        if(ch =='a' || ch == 'e' || ch == 'i'|| ch == 'o'|| ch == 'u')return true;
        return false;
    }
    bool isVowelsAtStartEnd(string s){
        return isVowel(s[0]) && isVowel(s[s.size()-1]);
    }
    vector<int> prefixVowelsStartEnd(vector<string> words){
        int n = words.size();
        vector<int>prefix(n);

        prefix[0] = isVowelsAtStartEnd(words[0]);

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + isVowelsAtStartEnd(words[i]);
        }

        return prefix;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix = prefixVowelsStartEnd(words);
        vector<int> res;

        for(int i = 0; i < words.size(); i++){
            cout << "index -> " << i << " -> " << prefix[i] << endl; 
        }

        for(auto v : queries){
            int l = v[0];
            int r = v[1];

            int count = prefix[r]-prefix[l]+isVowelsAtStartEnd(words[l]);
            res.push_back(count);
        }

        return res;
    }
};