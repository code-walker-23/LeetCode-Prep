class Solution {
    public int missingNumber(int[] nums) {
        int xOR = 0;
        for(int i = 0; i < nums.length; i++){
            xOR ^= nums[i];
            xOR ^= (i+1);
        }
        return xOR;
    }
}