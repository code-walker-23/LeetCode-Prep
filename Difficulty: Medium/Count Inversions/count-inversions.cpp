//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countInversion(vector<int>& arr, int low, int mid, int high){
    	int i = low;
    	int j = mid+1;
    	int count = 0;
    
    	while(i <= mid && j <= high){
    		if(arr[i] <= arr[j])count += (j-mid-1),i++;
    		else j++;
    	}
    
    	if(i <= mid){
    		count += (mid-i+1)*(high-mid);
    	}
    
    	return count;
    }
    
    void merge(vector<int>& arr, int low, int mid, int high) {
        int i = low, j = mid + 1, k = 0;
        vector<int> temp(high - low + 1);
    
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
    
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
    
        while (j <= high) {
            temp[k++] = arr[j++];
        }
    
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    
    void mergeSort(vector<int>& arr, int low, int high, int& count) {
        if (low < high) {
            int mid = low + (high - low) / 2;
    
            // Sort left half
            mergeSort(arr, low, mid, count);
    
            // Sort right half
            mergeSort(arr, mid + 1, high, count);
    
            // Count reverse pairs
            count += countInversion(arr, low, mid, high);
    
            // Merge both halves
            merge(arr, low, mid, high);
        }
    }
    
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        int count = 0;
    
        mergeSort(arr,0,n-1,count);
    
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends