//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // brute force will be O(n^2)
        
        // for(int i = 0; i < arr.size(); i++){
        //     for(int j = i+1; j < arr.size(); j++){
        //         if(arr[i]+arr[j] == target)return true;
        //     }
        // }
        // return false;
        
        // O(nlogn+n) = O(nlogn)
        
        sort(arr.begin(),arr.end());
        int low = 0;
        int high = arr.size()-1;
        
        while(low < high){
            int sum = arr[low]+arr[high];
            
            if(sum == target)return true;
            if(sum < target)low++;
            else high--;
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends