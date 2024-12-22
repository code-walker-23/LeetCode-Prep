//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        // when we do rotation k time , such that k == n , we got same array then rotation is 0 
        // int low = 0;
        // int high = arr.size()-1;
        //Time ->O(n)
        // int rotationCount = 0;
        // while(arr[low] > arr[high])low++,rotationCount++;
        
        // O(logn)
        // if(arr[low] < arr[high])return 0;
        
        // while(low < high){
        //     int mid = low + (high-low)/2;
            
        //     if(arr[mid] < arr[low]){
        //       high = mid-1;
        //     }else{
        //         if(arr[mid+1] > arr[mid])low = mid+1;
        //         else return mid+1;
        //     }
        // }
        // return low+1;
        
        // // return rotationCount;
        
        int low = 0; int high = nums.size() - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] < nums[high]){
                high = mid;
            } 
            else low = mid + 1;     
        }
        return low;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends