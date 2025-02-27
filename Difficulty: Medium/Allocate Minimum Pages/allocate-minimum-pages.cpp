//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool isPossible(vector<int>&arr,int k,int maxPagesAllocate){
        int students = 0;
        int pages = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > maxPagesAllocate)return false;
            pages += arr[i];
            if(pages > maxPagesAllocate)students++,pages = arr[i];
        }
        
        return (students+1) <= k;
    }
    int maxPages(vector<int>arr,int k){
        int maxBooksToSingle = arr.size()-(k-1);
        int maxi = INT_MIN;
        // sliding window
        int pagesSum = 0;
        for(int i = 0; i < maxBooksToSingle; i++)pagesSum+=arr[i];
        maxi = max(maxi,pagesSum);
        for(int i = 0; i <= k-2; i++){
            pagesSum -= arr[i];
            pagesSum += arr[i+maxBooksToSingle];
            
            maxi = max(maxi,pagesSum);
        }
        
        return maxi;
    }
    int findPages(vector<int> &arr, int k) {
        if(k > arr.size())return -1;
        
        int low = *min_element(arr.begin(),arr.end());
        int high = maxPages(arr,k);
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(arr,k,mid))high = mid-1;
            else low = mid+1;
        }
        
        return low;
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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends