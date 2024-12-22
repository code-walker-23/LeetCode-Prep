//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        
        // run for at least 2 length
        // while(low < high){
        //     int mid = low + (high-low)/2;
            
        //     if(arr[mid] < arr[low]){
        //         if(arr[mid-1] > arr[mid]){
        //             low = mid;
        //         }else{
        //             high = mid-1;
        //         }
        //     }else{
        //         if(arr[high] < arr[mid])low = mid+1;
        //         else high = mid;
        //     }
            
        // }
        // return arr[low];//arr[high]
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] < nums[high]){
                high = mid;
            } 
            else low = mid + 1;     
        }
        return nums[low];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends