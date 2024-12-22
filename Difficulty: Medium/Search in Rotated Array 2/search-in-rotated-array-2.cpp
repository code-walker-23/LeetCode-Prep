//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool Search(vector<int>& arr, int key) {
        // Code here
        int low = 0;
        int high = arr.size()-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] == key)return mid;
            
            if(arr[mid] < arr[low]){
                if(key > arr[mid] && key <= arr[high])low = mid+1;
                else high = mid-1;
            }else if(arr[mid] > arr[low]){
                if(key < arr[mid] && key >= arr[low])high = mid-1;
                else low = mid+1;
            }else{
                low++;
            }
            
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.Search(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends