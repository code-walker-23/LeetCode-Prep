class Solution {
    int firstOcc(int [] nums,int target){
        int n = nums.length;
        int low = 0;
        int high = n-1;
        int idx = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                idx = mid;
                high = mid-1;
            }else if(nums[mid] < target)low = mid+1;
            else high = mid-1;
        }

        return idx;
    }
    int lastOcc(int [] nums, int target){
        int n = nums.length;
        int low = 0;
        int high = n-1;
        int idx = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                idx = mid;
                low = mid+1;
            }else if(nums[mid] < target)low = mid+1;
            else high = mid-1;
        }

        return idx;
    }
    public int[] searchRange(int[] nums, int target) {
        int []res = new int[2];
        
        res[0] = firstOcc(nums,target);
        res[1] = lastOcc(nums,target);

        return res;
    }
}