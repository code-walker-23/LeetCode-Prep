class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // brute force will be generate all the subarrays and then select the subarray with maximum sum -> O(n^2)

        // optimized will be the kadane's algo in o(n)

        int n = nums.size();
        int maxSum = nums[0];
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxSum = max(maxSum,sum);
            if(sum < 0)sum = 0;
        }
        return maxSum;
    }
};