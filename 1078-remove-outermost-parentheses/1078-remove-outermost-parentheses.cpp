class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<int> st;
        //indices for prmitive decomposition
        vector<int>indices;
        string ans;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '(')st.push(s[i]);
            else{
                st.pop();
                if(st.empty())indices.push_back(i);
            }
        }

        int prev = -1;
        for(int i = 0; i < indices.size(); i++){
            int start = prev+2;
            int end = indices[i]-1;

            while(start <= end){
                ans+=s[start];
                start++;
            }
            prev = end+1;
        }

        return ans;
    }
};