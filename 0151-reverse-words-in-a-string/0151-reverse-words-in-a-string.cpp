class Solution {
public:
    void reverseString(string &s, int low,int high){
        while(low < high){
            char temp = s[low];
            s[low] = s[high];
            s[high] = temp;
            low++;
            high--;
        }
    }
    string reverseWords(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        string ans = "";

        // first reverse whole string
        reverseString(s,0,n-1);

        for(int i = 0; i < n; i++){
            if(s[i] == ' ' && l < r){
                reverseString(s,l,r-1);
                s[r] = ' ';
                r++;
                l = r;
            }else if(s[i] != ' '){
                s[r] = s[i];
                r++;
            }
        }

        if(l < r){
            reverseString(s,l,r-1);
            ans = s.substr(0,r);
        }else{
            ans = s.substr(0,r-1);
        }

        return ans;

    }
};













// class Solution {
// public:
//     string reverseWords(string s) {
//         int n = s.size();

//         stringstream ss(s);
//         string word;
//         string ans = "";
//         int i = 0;

//         while(ss >> word){
//             if(i == 0)ans = word;
//             else ans = word + " " + ans;
//             i++;
//         }

//         return ans;
//     }
// };






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