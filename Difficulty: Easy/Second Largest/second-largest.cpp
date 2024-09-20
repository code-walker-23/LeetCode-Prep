//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int largest(vector<int> arr){
        
        int max = arr[0];
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
        
        return max;
    }
    int print2largest(vector<int> &arr) {
        
        int max = largest(arr);
        int secondLargest = -1;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != max and arr[i] > secondLargest){
                secondLargest = arr[i];
            }
        }
        return secondLargest;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends