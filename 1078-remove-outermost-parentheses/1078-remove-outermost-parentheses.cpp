class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char> st;
        string ans;
        
        int prev = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                if(i > prev)ans+=s[i];
                st.push(s[i]);
            }
            else{
                st.pop();
                if(!st.empty())ans+=s[i];
                else prev = i+1;
            }
        }

        return ans;
    }
};