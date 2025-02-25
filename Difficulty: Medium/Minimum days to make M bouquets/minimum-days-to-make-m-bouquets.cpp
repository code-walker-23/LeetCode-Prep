//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool isPossible(vector<int>&bloomDay,int m,int k,int maxDays){
        int low = 0;
        int high = 0;
        int totalBoq = 0;

        while(high < bloomDay.size()){
            if(bloomDay[high] > maxDays){
                int totalAdj = high-low;
                totalBoq += (totalAdj/k);
                low = high+1;
            }
            high++;
        }
        if(low < high){
            int totalAdj = high-low;
            totalBoq += (totalAdj/k);
        }
        // cout << totalBoq << endl;
        return totalBoq >= m; 
    }
    int minDaysBloom(int m, int k, vector<int> &bloomDay) {
        if((long long)m*k > bloomDay.size())return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        long long high = *max_element(bloomDay.begin(), bloomDay.end());
        int minDays = high; // Initially, set to the largest possible value

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isPossible(bloomDay,m,k,mid)) {
                minDays = mid; // Update the minimum days
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return minDays; // Return the minimum speed found
    }
};


//{ Driver Code Starts.
int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        getline(cin, str);
        int m = stoi(str);
        getline(cin, str);
        int k = stoi(str);
        Solution obj;
        cout << obj.minDaysBloom(m, k, arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends