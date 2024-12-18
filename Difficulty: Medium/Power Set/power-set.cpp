//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
// 	Time and Space -> O(n)
	    void generatePowerSet(vector<string>&ans,int i,string sub,string &s){
	        if(i == s.size()){
	            ans.push_back(sub);
	            return; 
	        }
	        
	        generatePowerSet(ans,i+1,sub+s[i],s);
	        generatePowerSet(ans,i+1 ,sub,s);
	        
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    generatePowerSet(ans,0,"",s);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
		
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends