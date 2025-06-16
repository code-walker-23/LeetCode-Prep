class Solution {
    public void reverse(int[] nums) {
        int i = 0, j = nums.length - 1;
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }

    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int idx = -1;

        for(int j = n-1; j >= 1; j--){
            if(nums[j-1] < nums[j]){
                idx = j-1;
                break;
            }
        }

        if(idx == -1){
            // Array is sorted in descending manner
            // no next permutation exist return sorted in asc order
            // just do reverse in O(n) better than sort O(nlogn)
            reverse(nums);
        }else{
            // index of the element which > than nums[idx] and min also
            int newIdx = -1;
            for(int i = idx+1; i < n; i++){
                if(nums[i] > nums[idx]){
                    if(newIdx == -1){
                        newIdx = i;
                    }else if(nums[i] < nums[newIdx]){
                        newIdx = i;
                    }
                }
            }

            int temp = nums[idx];
            nums[idx] = nums[newIdx];
            nums[newIdx] = temp; 

            Arrays.sort(nums,idx+1,n);
        }
    }
}