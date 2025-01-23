//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        for(int i = 1; i < n; i++){
            int j = i-1;//till then sorted array
            int temp = arr[i];
            
            while(temp < arr[j] && j >= 0){
                arr[j+1] = arr[j]; 
                j--;
            }
            
            arr[j+1] = temp;
        }
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.insertionSort(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends