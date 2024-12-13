//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    // better solution
	    // O(n)
	   // vector<int> res;
	   // for(int i = 2; N > 1; i++){
	   //     if(N%i == 0){
	   //         res.push_back(i);
	   //         while(N%i == 0){
	   //             N/=i;
	   //         }
	   //     }
	   // }
	   // return res;
	   
	   // naive solution
	   //O(n*sqrt(n))
	   //if(n == 2 || n == 3) return {n};
	   //vector<int> v;
	   //for(int i = 2; i < n; i++){
	   //    if(isPrime(i)){
	   //        int x = i;
	   //        while(n%x == 0){
	   //            v.push_back(i);
	   //            x = x*i;
	   //        }
	   //    }
	   //}
	    
	    // efficient
	   vector<int> v;
	   for(int i = 2; i*i <= N; i++){
	       if(N%i == 0){
	           v.push_back(i);
	           while(N%i == 0){
	                N/=i;
	           }
	       }
	   }
	   //cout << N << endl;
	   if(N > 1)v.push_back(N);
	   return v;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends