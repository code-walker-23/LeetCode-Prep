//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isPossible(vector<int>nums,int k,int maxSum){
        int subArr = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > maxSum){
                subArr++;
                sum = nums[i];
            }
        }

        return subArr <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low <= high){
            int mid = low + (high-low)/2;

            if(isPossible(nums,k,mid))high = mid-1;
            else low = mid+1;
        }

        return low;
    }
    int splitArray(int arr[] ,int N, int k) {
        vector<int>nums(N);
        for(int i = 0; i < N; i++)nums[i] = arr[i];
        
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low <= high){
            int mid = low + (high-low)/2;

            if(isPossible(nums,k,mid))high = mid-1;
            else low = mid+1;
        }

        return low;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends