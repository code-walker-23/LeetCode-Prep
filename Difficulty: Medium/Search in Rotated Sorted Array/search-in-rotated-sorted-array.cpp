//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int low = 0;
        int high = arr.size()-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] == key)return mid;
            
            if(arr[mid] < arr[low]){
                if(key > arr[mid] && key <= arr[high])low = mid+1;
                else high = mid-1;
            }else{
                if(key < arr[mid] && key >= arr[low])high = mid-1;
                else low = mid+1;
            }
            
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends