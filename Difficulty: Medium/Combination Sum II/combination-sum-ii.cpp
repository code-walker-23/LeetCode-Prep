//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void subsequencesWithTarget(int idx,vector<int>arr,vector<int>v,vector<vector<int>>&res,int target, unordered_set<int>s){
        if(idx == arr.size()){
            if(target == 0){
                sort(v.begin(),v.end());
                res.push_back(v);
            }
            return;
        }

        if(s.find(arr[idx]) == s.end() && arr[idx] <= target){
            v.push_back(arr[idx]);
            subsequencesWithTarget(idx+1,arr,v,res,target-arr[idx],s);
            s.insert(arr[idx]);
            v.pop_back();
        }

        subsequencesWithTarget(idx+1,arr,v,res,target,s);

    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        vector<vector<int>>res;
        vector<int>v;
        unordered_set<int>s;
        // second method will be removing duplicates and then pass
        subsequencesWithTarget(0,arr,v,res,k,s);
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends