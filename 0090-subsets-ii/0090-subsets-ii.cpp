class Solution {
public:

    void generateSubsets(vector<vector<int>>& ans, vector<int>& nums, vector<int>& current, int index) {
        ans.push_back(current);
        for(int i = index; i < nums.size(); i++){
            if (i > index && nums[i] == nums[i - 1])continue;
            
            current.push_back(nums[i]);
            generateSubsets(ans,nums,current,i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> current;
        
        sort(nums.begin(),nums.end());
        generateSubsets(ans,nums,current,0);

        return ans;
    }
};