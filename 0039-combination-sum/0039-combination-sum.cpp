class Solution {
public:
    void subsequencesWithTarget(int idx,vector<int>arr,int sum,vector<int>v,vector<vector<int>>&res,int target){

        if(sum > target)return;
        if(idx == arr.size()){
            if(sum == target){
                res.push_back(v);
            }
            return;
        }

        v.push_back(arr[idx]);
        sum += arr[idx];
        subsequencesWithTarget(idx,arr,sum,v,res,target);

        v.pop_back();
        sum -= arr[idx];
        subsequencesWithTarget(idx+1,arr,sum,v,res,target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>v;
        subsequencesWithTarget(0,candidates,0,v,res,target);
        return res;
    }
};