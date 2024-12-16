//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        
        // // first loop is giving numbers from 1 to n
        // // inner loop is cheking for all 32 bits set or not
        // int count = 0; // storing the count of set bits
        // O(NlogN)
        // for(int num = 1; num <= n; num++){
        // this will run for logn in worst case when all bits are set
        //     while(num){
        //         num = num&(num-1);
        //         count++;
        //     }
        // }
        // return count;
        
        // storing the the set bits for 8-bit integers 0 to 255
        
        // int tb[256];
        // tb[0] = 0;
        // int count = 0;
        
        // O(1)
        // for(int i = 1; i < 256; i++){
        //     tb[i] = tb[i&(i-1)] + 1;
        // }
        
        // O(N)
        // for(int i = 1; i <= n; i++){
        //     count += (tb[i&255]+tb[(i>>8)&255]+tb[(i>>16)&255]+tb[i>>24]);
        // }
        
        // But all above give the TLE N =10^9
        
        if(n == 1 || n == 0)return n;
        
        int x = 1;
        int powX = 0;
        while(x <= n){
            x*=2;
            powX++;
        }
        // reversing action of extra iteration
        powX--;  // power count
        x/=2; // containig 2^powX
        
        int setBitsCount = powX*(x/2) + (n-x+1) + countSetBits(n-x);  
        
        return setBitsCount;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  
cout << "~" << "\n";
}
	  return 0;
}

// } Driver Code Ends