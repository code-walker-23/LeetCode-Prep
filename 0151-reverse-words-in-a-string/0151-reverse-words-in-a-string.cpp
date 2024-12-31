class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        stringstream ss(s);
        string word;
        string ans = "";
        int i = 0;

        while(ss >> word){
            if(i == 0)ans = word;
            else ans = word + " " + ans;
            i++;
        }

        return ans;
    }
};






// class Solution {
// public:
// // Time -> O(n) and Space -> O(number of words) ->we can optimize this 
//     string reverseWords(string s) {
//         // Naive Approach
//         int n = s.size();
//         vector<string> words;
//         string str="";

//         for(int i = 0; i < n; i++){
//             if(s[i] != ' ')str+=s[i];
//             else{
//                 if(str != "")words.push_back(str);
//                 str="";
//             }
//         }

//         if(str!="")words.push_back(str);

//         string ans = "";
//         for(int i = words.size()-1; i > 0; i--){
//             ans+=(words[i]+" ");
//         }
//         ans+=words[0];

//         return ans;
//     }
// };