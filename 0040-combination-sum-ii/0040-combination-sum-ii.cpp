class Solution {
public:
    void subsequencesWithTarget(int idx,vector<int>arr,vector<int>v,vector<vector<int>>&res,int target, unordered_set<int>s){
        if(idx == arr.size()){
            if(target == 0){
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>v;
        unordered_set<int>s;
        subsequencesWithTarget(0,candidates,v,res,target,s);
        return res;
    }
};