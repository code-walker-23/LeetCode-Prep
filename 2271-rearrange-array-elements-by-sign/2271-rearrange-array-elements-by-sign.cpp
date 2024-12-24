class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Brute force will be using extra space O(n) and time O(2n)

        int n = nums.size();
        vector<int>pos;
        vector<int>neg;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0)pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        int k = 0;
        for(int i = 0; i < n/2; i++){
            nums[k] = pos[i];
            nums[k+1] = neg[i];
            k+=2;
        }

        return nums;

        // optimized will be in the constant space
    }
};