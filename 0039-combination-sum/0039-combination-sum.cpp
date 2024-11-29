class Solution {
public:
    void subsequencesWithTarget(int idx,vector<int>arr,vector<int>v,vector<vector<int>>&res,int target){
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