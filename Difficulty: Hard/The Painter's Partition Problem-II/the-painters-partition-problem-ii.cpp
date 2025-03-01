//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
   int isPossible(vector<int>&boards,int k,int maxTime){
        int n = boards.size();
        int painters = 1;
        int time = 0;
    
        for(int i = 0; i < n; i++){
            time +=boards[i];
            if(time > maxTime)painters++,time = boards[i];    
        }
    
        return painters <= k;
    
    }
    int minTime(vector<int> &boards, int k)
    {
        int low = *max_element(boards.begin(),boards.end());
        int high = accumulate(boards.begin(),boards.end(),0);
    
        while(low <= high){
            int mid = low+(high-low)/2;
    
            if(isPossible(boards,k,mid)){
                high = mid-1;
            }else low = mid+1;
        }
    
        return low;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends