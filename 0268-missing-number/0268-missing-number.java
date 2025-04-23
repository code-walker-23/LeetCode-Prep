class Solution {
    public int missingNumber(int[] nums) {
        // first method
        // int xOR = 0;
        // for(int i = 0; i < nums.length; i++){
        //     xOR ^= nums[i];
        //     xOR ^= (i+1);
        // }
        // return xOR;

        // second method
        int n = nums.length;
        long sum = n*(n+1)/2;
        long arrSum = 0;

        for(int i = 0; i < n; i++)arrSum += nums[i];

        return (int)(sum-arrSum);
    }
}