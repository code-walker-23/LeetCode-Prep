//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    bool isOperator(char ch){
        if(ch == '+' || ch == '-' || ch == '^' || ch == '*' || ch == '/')return true;
        return false;
    }
    string infixToPostfix(string& s) {
        // Your code here
        map<char,int>mapi;
        mapi['+'] = 0;
        mapi['-'] = 0;
        mapi['/'] = 1;
        mapi['*'] = 1;
        mapi['^'] = 2;
        
        string ans="";
        stack<char>st;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')st.push(s[i]);
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans+=st.top();
                    st.pop();
                }
                if(!st.empty())st.pop();
            }
            else if(isOperator(s[i])){
                if(st.empty()){
                    st.push(s[i]);
                }else{
                    while(!st.empty() && st.top() != '(' && (mapi[st.top()] >= mapi[s[i]])){
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }else{
                ans+=s[i];
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends