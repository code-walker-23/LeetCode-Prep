//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  // T(n) = 2*T(n/2) + O(2*n)(merging+counting) => O(2nlogn) = O(nlogn)
    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int count = 0;
        int i = low;
        int j = mid + 1;
        // O(sum of sizes of two sorted list)
       while(i <= mid && j <= high){
		    if(arr[i] <= 2LL*arr[j])count += (j-mid-1),i++;
		    else j++;
	    }
        //  while (i <= mid) {
        //     while (j <= high && arr[i] > 2LL * arr[j]) {
        //         j++;
        //     }
        //     count += (j - mid - 1);
        //     i++;
        // }

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
            count += countPairs(arr, low, mid, high);

            // Merge both halves
            merge(arr, low, mid, high);
        }
    }
    int countRevPairs(int n, vector<int> arr) {
        int count = 0;
        mergeSort(arr, 0, n-1, count);
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends