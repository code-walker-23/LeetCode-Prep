//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // Time Complexity -> O(Q*x) => worst case Q = n, and Indices = [0,1,...,N-1] => O(N^2)
    // Space -> O(Q)
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        // vector<int>countNGES(queries);
        
        // while(queries--){
        //     int eleIdx = indices[queries];
        //     int count = 0;
            
        //     for(int i = eleIdx+1; i < n; i++)
        //         if(arr[eleIdx] < arr[i])count++;
            
        //     countNGES[queries] = count;
        // }
        
        // return countNGES;
        
       stack<int> s1;
       stack<int> s2;
       int el=0;
       vector<int> count(n,0);
       vector<int> ans;
       
       for(int i=n-1;i>=0;i--){
           while(!s2.empty() && arr[i] < s2.top()){
               el=s2.top();
               s2.pop();
               s1.push(el);
           }
           while(!s1.empty() && arr[i] >= s1.top()){
               el=s1.top();
               s1.pop();
               s2.push(el);
           }
           if(!s1.empty()) count[i]=s1.size();
           s1.push(arr[i]);
       }
       
       for(int j=0;j<queries;j++){
           ans.push_back(count[indices[j]]);
       }
       return ans;
    }

};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends