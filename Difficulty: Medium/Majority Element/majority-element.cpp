//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        //brute force will be O(n) both time and space
        // int n = nums.size();
        // unordered_map<int,int> mapi;

        // for(int i = 0; i < n; i++)mapi[nums[i]]++;
        // int ans = 0;
        // for(auto p : mapi){
        //     if(p.second > n/2){
        //         ans = p.first;
        //         break;
        //     }
        // }
        // return ans;

        // Better in constant space
        // This Moore's Voting Algorithm
        // If the majority element is there then it must be in majority in some portion of the array
        int n = nums.size();
        int count = 0;
        int element;

        for(int i = 0; i < n; i++){
            if(count == 0){
                element = nums[i];
                count = 1;
            }
            else if(nums[i] == element)count++;
            else count--;

        }
        // it is not necessary that if count > 0 then majority exist
        int c = 0;
        for(int i = 0; i < n; i++)if(nums[i] == element)c++;
        
        if(c > n/2)
            return element;
        return -1;
    }
    /*
    

The **Moore Voting Algorithm** identifies a potential candidate for the majority element in an array. However, the algorithm does not guarantee that the candidate is a majority element—it only finds a candidate that might be a majority. A final verification step is needed to confirm whether the candidate is indeed a majority element.

Here's an example where the count is greater than 0, but there is no majority element:

### Example:
Array: `[1, 2, 3, 1, 2, 1]`

1. **Step 1**: Find the candidate:
   - Initial candidate: `1` (count = 1)
   - Process each element:
     - `1`: Count becomes 2.
     - `2`: Count decreases to 1.
     - `3`: Count decreases to 0. Reset candidate to `3`.
     - `1`: Candidate becomes `1` (count = 1).
     - `2`: Count decreases to 0. Reset candidate to `2`.
     - `1`: Candidate becomes `1` (count = 1).

   The algorithm determines the candidate as `1`.

2. **Step 2**: Verify the candidate:
   - Count the occurrences of `1` in the array: `1` appears **3 times**.
   - Total elements = `6`.
   - Majority condition: An element must appear **more than 6/2 = 3 times**.

   Since `1` appears exactly 3 times (not more than 3), it is **not a majority element**.

### Explanation:
The count > 0 during the candidate selection process does not necessarily mean that the candidate is a majority element. This example highlights why the verification step is crucial.*/
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends