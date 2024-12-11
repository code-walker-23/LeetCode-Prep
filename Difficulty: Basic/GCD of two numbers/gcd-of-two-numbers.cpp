//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int gcd(int a, int b) {
        if(b == 0)return a;
    //   for(int i = min(a,b); i >= 1; i++){
    //       if(a%i == 0 && b%i == 0){
    //           return i;
    //       }
    //   }
    // This is the traditional way of finding the gcd of two numbers
    // Let a = 17,  b = 13
    // gcd(17,13) ==> gcd(13,17%13) ==> gcd(13,4) ==> gcd(4,13%4) ==> gcd(4,1) ==> gcd(1,4%1) ==> gcd(1,0) ==> divisor becomes zero then the hcf is dividend a    
    // we can also do this with recursion    
        // while(a%b != 0){
        //     int rem = a%b;
        //     a = b;
        //     b = rem;
        // }
        
        return gcd(b,a%b);
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