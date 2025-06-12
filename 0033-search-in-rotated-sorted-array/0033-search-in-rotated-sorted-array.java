class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target)return mid;

            if(nums[mid] <= nums[n-1]){
                // no rotation
                if(nums[mid] < target && target <= nums[n-1])low = mid+1;
                else high = mid-1;
            }else{
                // nums[mid] > nums[n-1]
                if(target >= nums[0] && target < nums[mid])high = mid-1;
                else low = mid+1;
            }   
        }

        return -1;
    }
}