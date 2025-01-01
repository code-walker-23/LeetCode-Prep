class Solution {
public:
    const int MOD = 1000000007;

    // i have to remove equality one of them otherwise it includes twice duplicate in subarraycount

    // eg ->  _,_,_,58,_,_,58 first 58 has pse = -1 nse = before second 58 and nse = n and second 58 has nse = n and pse = -1
    vector<int> previousSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> pse(n, -1);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                pse[i] = s.top();
            }
            s.push(i);
        }
        return pse;
    }

    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> nse(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                nse[i] = s.top();
            }
            s.push(i);
        }
        return nse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = previousSmallerElement(arr);
        vector<int> nse = nextSmallerElement(arr);

        long long totalSum = 0;

        for (int i = 0; i < n; i++) {
            long long leftCount = i - pse[i];
            long long rightCount = nse[i] - i;
            totalSum = (totalSum + leftCount * rightCount % MOD * arr[i] % MOD) % MOD;
        }

        return totalSum;
    }
};




// // Brute force -> O(n^2)
//         int n = arr.size();
//         int totalSum = 0;

//         for(int i = 0; i < n; i++){
//             int mini = arr[i];
//             totalSum += arr[i];

//             for(int j = i+1; j < n; j++){
//                 mini = min(mini,arr[j]);
//                 totalSum = (totalSum+mini)%mod;
//             }
//         }

//         return totalSum;