//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int gcd(int a, int b) {
    //   for(int i = min(a,b); i >= 1; i++){
    //       if(a%i == 0 && b%i == 0){
    //           return i;
    //       }
    //   }
    
        while(a%b != 0){
            int rem = a%b;
            a = b;
            b = rem;
        }
        
        return b;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.gcd(a, b);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends