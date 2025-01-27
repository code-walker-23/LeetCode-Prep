//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<string>> ans;
        int minLevel = 0;

        unordered_set<string> s(wordList.begin(), wordList.end());
        if (s.find(endWord) == s.end()) return {};  // If endWord is not in the wordList, no paths exist.

        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> wordsToRemove;  // Temporary set to delay erasure.
        int currLevel = 1;

        while (!q.empty()) {
            int size = q.size();
            if(minLevel != 0 && currLevel > minLevel)break;
            
            for (int i = 0; i < size; i++) {
                vector<string> seq = q.front();
                q.pop();

                string word = seq[currLevel-1];

                if (word == endWord) {
                    minLevel = seq.size();
                    ans.push_back(seq);
                } else {
                    for (int j = 0; j < word.size(); j++) {
                        string dummyWord = word;
                        for (int k = 0; k < 26; k++) {
                            char ch = 'a' + k;
                            dummyWord[j] = ch;

                            if (s.find(dummyWord) != s.end()) {
                                wordsToRemove.insert(dummyWord);
                                seq.push_back(dummyWord);
                                q.push(seq);
                                seq.pop_back();
                            }
                        }
                    }
                }
            }

            // Erase all words that were visited in this level.
            for (const auto& word : wordsToRemove) {
                s.erase(word);
            }
            wordsToRemove.clear();
            currLevel++;
        }

        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends