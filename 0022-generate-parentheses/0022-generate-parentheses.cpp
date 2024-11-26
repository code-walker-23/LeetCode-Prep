class Solution {
public:
// Two cases : OB >= CB during the recursive call
// we will never get that case OB = CB = n; when we reach OB=n, then OB>CB , then we will take remaining closing braces and then push the string of required n pairs of parenthesis.
// Time Complexity Analysis : Depends on How many well formed parentheses we can generate from n pair of parenthesis.
// that is catalan number which (2n)!/(n+1)!*n!.

// Space Complexity -> mazimum depth will be n -> O(n). 

        void generateParenthesis(int openingBraces,int closingBraces,int n,vector<string> &res,string s){
        // if(openingBraces == n){
        //     while(closingBraces < n){
        //         s+=")";
        //         closingBraces++;
        //     }
        //     res.push_back(s);
        //     return;
        // }
        // we can omit while in base case
        if(openingBraces == n && closingBraces == n){
           res.push_back(s);
           return;
        }
        if(openingBraces < n)
            generateParenthesis(openingBraces+1,closingBraces,n,res,s+"(");
        if(openingBraces > closingBraces){
            generateParenthesis(openingBraces,closingBraces+1,n,res,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis(0,0,n,res,"");
        // cout << res.size() << endl;
        return res;
    }
};