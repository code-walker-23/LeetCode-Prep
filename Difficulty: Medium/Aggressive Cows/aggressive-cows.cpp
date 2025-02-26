//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    
    bool isPossible(vector<int>&arr,int k,int minDis){
        int cowsPlaced = 1;
        int prevCowPos = arr[0];
        
        for(int i = 1; i < arr.size(); i++){
            if(prevCowPos+minDis <= arr[i]){
                prevCowPos = arr[i];
                cowsPlaced++;
                
                if(cowsPlaced == k)return true;
            }
        }
        
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        
        int low = 1; int high = stalls[n-1]-stalls[0];
        int largestMinDis = high;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(isPossible(stalls,k,mid))largestMinDis= mid,low = mid+1;
            else high = mid-1;
        }
        
        return largestMinDis;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends