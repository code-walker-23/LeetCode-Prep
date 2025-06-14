class Solution {
    public int findPeakElement(int[] arr) {
        // O(n)-> Approach
        int n = arr.length;
        // if(n == 1)return 0;

        // if(nums[0] > nums[1])return 0;
        // if(nums[n-1] > nums[n-2])return n-1;

        // for(int i = 1; i < n-1; i++){
        //     if(nums[i] > nums[i-1] && nums[i] > nums[i+1])return i;
        // }

        for(int i = 0; i < n; i++){
            if((i == 0 || arr[i] > arr[i-1]) && (i == n-1 || arr[i] > arr[i+1]))return i;
        }

        return -1;
    }
}