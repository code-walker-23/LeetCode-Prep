//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  // O(logn+logn) = O(logn) better than linear search -> O(n)
    int firstOcc(vector<int>arr,int target){
        int low = 0;
        int high = arr.size()-1;
        int firstOccurence = -1;

        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] == target){
                firstOccurence = mid;
                high = mid-1;
            }else if(arr[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return firstOccurence;
    }
    int lastOcc(vector<int>arr,int target){
        int low = 0;
        int high = arr.size()-1;
        int lastOccurence = -1;

        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] == target){
                lastOccurence = mid;
                low = mid+1;
            }else if(arr[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return lastOccurence;
    }
    int countFreq(vector<int>& arr, int target) {
        int firstO = firstOcc(arr,target);
        int lastO = lastOcc(arr,target);
        
        if(firstO == -1 && lastO == -1)return 0;
        return (lastO-firstO+1);
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends