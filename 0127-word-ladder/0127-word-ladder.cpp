class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // brute force
        unordered_set<string>s;
        for(auto word : wordList)s.insert(word);
        s.erase(beginWord);
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int count = 0;

        while(!q.empty()){
            pair<string,int> p = q.front();
            q.pop();

            string word = p.first;
            int level = p.second;

            if(word == endWord)return level;
            
            for(int i = 0; i < word.size(); i++){
                string dummyWord = word;
                for(int j = 0; j < 26; j++){
                    char ch = 'a'+j;
                    dummyWord[i] = ch;

                    if(s.find(dummyWord) != s.end()){
                        s.erase(dummyWord);
                        q.push({dummyWord,level+1});
                    }
                }
            }
        }

        return 0;
    }
};