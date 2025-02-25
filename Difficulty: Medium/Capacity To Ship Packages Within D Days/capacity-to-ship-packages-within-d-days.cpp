//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool isPossibleToShip(vector<int>&weights,int days,int shipCap){
        int currCap = shipCap;
        // we are taking this one because , you will always end up loading packages or package at last in ship , so we have to count that day also, we may increment by one after loop
        int daysReq = 1;

        for(int i  = 0; i < weights.size(); i++){
            if(weights[i] <= currCap)currCap -= weights[i];
            // we make sure that shipCap will always be greater than or equal to the weights[i] by taking low as max of weights
            else currCap = shipCap-weights[i],daysReq++;
        }
        return daysReq <= days;
    }
  
    int leastWeightCapacity(int arr[], int n, int days) {
        vector<int>weights(n);
        for(int i = 0; i < n; i++)weights[i] = arr[i];
        
        int totalWeight = 0;
        for(int i = 0; i < weights.size(); i++)totalWeight += weights[i];

        int low = *max_element(weights.begin(),weights.end());
        int high = totalWeight;
        int atLeastShipCap = high;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossibleToShip(weights,days,mid)){
                high = mid-1;
                atLeastShipCap = mid;
            }else low = mid+1;
        }

        return atLeastShipCap;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends