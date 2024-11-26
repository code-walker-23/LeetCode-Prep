class Solution {
public:
// Time Complexity -> generating all the subsets of set -. 2^n -> O(2^n)
// Space Complexity -> maximum height, at most i == n -> O(n) 
     void generateAllSubsets(vector<int>v,vector<vector<int>> &res,int i,vector<int>&nums){
    if(i == nums.size()){
        res.push_back(v);
        return;
    }
    // including the element
    v.push_back(nums[i]);
    generateAllSubsets(v,res,i+1,nums);
    // excluding the element
    v.pop_back();
    generateAllSubsets(v,res,i+1,nums);
 } 
 
 vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int>v;
    generateAllSubsets(v,res,0,nums);
    return res;
 }
};