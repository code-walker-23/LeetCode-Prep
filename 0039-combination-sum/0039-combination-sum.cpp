class Solution {
public:
// Time Complexity -> O(2^t*k) where k is the size v in base case 
// we are making 2^t subsequences in each we adding v of size k 
    void subsequencesWithTarget(int idx,vector<int>arr,vector<int>v,vector<vector<int>>&res,int target){
        if(target == 0){
            res.push_back(v);
            return;
        }
        if(idx == arr.size()){
            if(target == 0){
                res.push_back(v);
            }
            return;
        }

        if(arr[idx] <= target){
            v.push_back(arr[idx]);
            subsequencesWithTarget(idx,arr,v,res,target-arr[idx]);
            v.pop_back();
        }

        subsequencesWithTarget(idx+1,arr,v,res,target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>v;
        subsequencesWithTarget(0,candidates,v,res,target);
        return res;
    }
};