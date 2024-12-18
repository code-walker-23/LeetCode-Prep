//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // // naive solution -> O(n^2)->tle
        // vector<long long int> ans;
        // for(long long int i = 0; i < n; i++){
        //     if(arr[i] != -1){
        //         int count  = 1;
        //         for(long long int j = i+1; j < n; j++){
        //             if(arr[j] == arr[i])count++,arr[j]=-1;
        //         }
        //         if(count%2)ans.push_back(arr[i]);
        //         // skip some iterations
        //         if(ans.size() == 2)break;
        //     }
        // }
        
        // if(ans[0] < ans[1]) return {ans[1],ans[0]};
        // return ans;
        
        int xOR = 0;
        for(int i = 0; i < n; i++){
            xOR ^= arr[i];
        }
        // finding the last set in the xor of two odd occuring numbers
        int setBitPos = 0;
        while(xOR){
            if(xOR%2)break;
            setBitPos++;
            xOR>>=1;
        }
        // creating the mask to divide the numbers into segments -> one is having set bit at that mask position and other has unset
        int mask = 1<<setBitPos;
        long long int num1 = 0;
        long long int num2 = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i]&mask){
                num1^=arr[i];
            }else{
                num2^=arr[i];
            }
        }
        
        if(num1 > num2) return {num1,num2};
        return {num2,num1};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends