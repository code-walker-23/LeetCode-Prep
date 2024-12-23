//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        //brute force will be O(n) both time and space
        // int n = nums.size();
        // unordered_map<int,int> mapi;

        // for(int i = 0; i < n; i++)mapi[nums[i]]++;
        // int ans = 0;
        // for(auto p : mapi){
        //     if(p.second > n/2){
        //         ans = p.first;
        //         break;
        //     }
        // }
        // return ans;

        // Better in constant space
        // This Moore's Voting Algorithm
        // If the majority element is there then it must be in majority in some portion of the array
        int n = nums.size();
        int count = 0;
        int element;

        for(int i = 0; i < n; i++){
            if(count == 0){
                element = nums[i];
                count = 1;
            }
            else if(nums[i] == element)count++;
            else count--;

        }
        
        int c = 0;
        for(int i = 0; i < n; i++)if(nums[i] == element)c++;
        
        if(c > n/2)
            return element;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends