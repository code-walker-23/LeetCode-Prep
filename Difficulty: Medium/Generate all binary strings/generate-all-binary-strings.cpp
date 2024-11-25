//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
 void generateAllStrings(int n, string s, vector<string> &res){
    // base case
    if(s.size() == n){
        res.push_back(s);
        return;
    }
    // for the initial call
    if(s == ""){
        generateAllStrings(n,"0",res);
        generateAllStrings(n,"1",res);
    }
    // we have to use if elseif to prevent when after execution it comes back to the first call and execute else 
    if(s[s.size()-1] == '0'){
        string stringWithZero = s+"0";
        string stringWithoutZero = s+"1";
        generateAllStrings(n,stringWithZero,res);
        generateAllStrings(n,stringWithoutZero,res);
    }else if(s[s.size()-1] == '1'){
        string stringWithZero = s+"0";
        generateAllStrings(n,stringWithZero,res);
    }

 }

 vector<string> generateBinaryStrings(int num){
    vector<string> res;
    generateAllStrings(num,"",res);
    return res;
 }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends