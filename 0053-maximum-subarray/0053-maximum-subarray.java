class Solution {
    public int maxSubArray(int[] nums) {
        // we can loop the subarray in O(n^3) -> i = 0-> n-1, j = 0->n-1 and k = i -> j;
        // we can loop in the O(n^2) -> i = 0->n-1 and j = i -> n-1
        int sum = 0;
        int maxSum = Integer.MIN_VALUE; 
        
        for(int i = 0; i < nums.length; i++){
            sum += nums[i];
            maxSum = Math.max(maxSum,sum);
            // Intuition behind the making sum = 0 when it is -ve
            // If there exist a subarray with maxSum > 0 then we can not have maxSum < 0 that is why we do sum = 0
            // If there exist a subarray with maxSum < 0 (all elements < 0) then then we will try to find the single element with maximum value
            if(sum < 0)sum = 0;
        }

        return maxSum;
    }
}