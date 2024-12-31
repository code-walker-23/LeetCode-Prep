//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool longestConsecutive(vector<int>& nums, int target){
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longestConsecutiveSequence = 0;
        for(auto num : nums){
            int currentNumber = num;
            int currentConsecutiveSequence = 1;
            while(longestConsecutive(nums, currentNumber+1)){
                currentNumber += 1;
                currentConsecutiveSequence += 1;
            }
            longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
        }
        return longestConsecutiveSequence;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends