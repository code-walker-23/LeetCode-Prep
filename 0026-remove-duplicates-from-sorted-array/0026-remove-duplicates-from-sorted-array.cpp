class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size();
       vector<int> expectedNums;
       expectedNums.push_back(nums[0]);
       for(int i = 0; i < n-1; i++){
            if(nums[i] != nums[i+1]){
                expectedNums.push_back(nums[i+1]);
            }
       }
       for(int i = 0; i < expectedNums.size(); i++){
            nums[i] = expectedNums[i];
       }
       return expectedNums.size();
    }
};