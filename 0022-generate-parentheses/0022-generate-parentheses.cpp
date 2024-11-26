class Solution {
public:
        void generateParenthesis(int openingBraces,int closingBraces,int n,vector<string> &res,string s){
        if(openingBraces == n){
            while(closingBraces < n){
                s+=")";
                closingBraces++;
            }
            res.push_back(s);
            return;
        }
        generateParenthesis(openingBraces+1,closingBraces,n,res,s+"(");
        if(openingBraces>closingBraces){
            generateParenthesis(openingBraces,closingBraces+1,n,res,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis(0,0,n,res,"");
        return res;
    }
};