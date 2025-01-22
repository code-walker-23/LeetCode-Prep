class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n > m)return false;

        vector<int>s1CharCount(26,0);
        vector<int>s2CharCount(26,0);

        for(auto ch : s1)s1CharCount[ch-'a']++;
        
        int countSameOccurence = 0;
        for(int i = 0; i < n; i++){
            s2CharCount[s2[i]-'a']++;
            if(s2CharCount[s2[i]-'a'] == s1CharCount[s2[i]-'a'])countSameOccurence++;
        }

        int distinctCharCountS1 = 0;
        for(int i = 0; i < 26; i++)if(s1CharCount[i])distinctCharCountS1++;

        if(countSameOccurence == distinctCharCountS1)return true;

        for(int i = 0; i < m-n; i++){
            cout << s2[i] << endl;
            if(s2CharCount[s2[i]-'a'] == s1CharCount[s2[i]-'a'])countSameOccurence--;
            s2CharCount[s2[i]-'a']--;

            s2CharCount[s2[i+n]-'a']++;
            if(s2CharCount[s2[i+n]-'a'] == s1CharCount[s2[i+n]-'a'])countSameOccurence++;

            if(countSameOccurence == distinctCharCountS1)return true;
        }

        return false;
    }
};