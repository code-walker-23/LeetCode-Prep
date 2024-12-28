//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &nums, int n){
        vector<long long>nge(n,-1);
        stack<long long>s;

        for(int i = n-1; i >=0 ; i--){
            // O(n)
            while(!s.empty() && s.top() <= nums[i])s.pop();
            
            // O(n^2)-> when array is in decreasing order from right side, we have to got to the left
            if(s.empty()){
                // we did not find next greater element to the right of the element , will shift to the left(this is    circular, starting from the next of the element to the before it occurs considered as a right )
                for(int j = 0; j < i; j++){
                    if(nums[j] > nums[i]){
                        nge[i] = nums[j];
                        break;   
                    }
                }
            }
            // we found to the right
            else nge[i] = s.top();

            s.push(nums[i]);
        }
        return nge;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends