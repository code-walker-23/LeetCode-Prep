//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends