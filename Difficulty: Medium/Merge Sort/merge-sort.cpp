//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  // merge will take O(n+m) but both are equal then O(n)
    void merge(vector<int>&arr,int start,int mid,int end){
        int i = start;
        int j = mid+1;
        int k = 0;
        vector<int>newArray(end-start+1,0);
        
        while(i <= mid && j <= end){
            if(arr[i] < arr[j]){
                newArray[k++] = arr[i++];
            }else{
                newArray[k++] = arr[j++];
            }
        }
        
        while(i <= mid)newArray[k++] = arr[i++];
        while(j <= end)newArray[k++] = arr[j++];
        
        for(int i = start; i <= end; i++){
            arr[i] = newArray[i-start];
        }
        
    }
    // recusion will be of logn length
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        
        if(l < r){
            int mid = (l+r)/2;
            
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            
            merge(arr,l,mid,r);
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
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends