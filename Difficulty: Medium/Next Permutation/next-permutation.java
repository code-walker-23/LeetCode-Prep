class Solution {
    void reverse(int[] nums, int low,int high) {
        while (low < high) {
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }
    }

    void nextPermutation(int[] nums) {
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
            reverse(nums,0,n-1);
        }else{
            // index of the element which > than nums[idx] and min also
            int newIdx = -1;
            for(int i = idx+1; i < n; i++){
                // adding equals to also to avoid sorting
                if(nums[i] > nums[idx]){
                    if(newIdx == -1){
                        newIdx = i;
                    }else if(nums[i] <= nums[newIdx]){
                        newIdx = i;
                    }
                }
            }

            // there is intuition is that you got idx after the idx , from idx+1 elements in decreasing order
            // Inorder to avoid sort from idx+1 , you can just reverse it using O(n)
            // In my algo that using sort i am finding greater from idx+1 and after got this , i will search for element strictly greater if there are equal no swap 
            // so that will not maintain the decreasing order from idx+1
            // To do this , I have two ways
            // 1. put >= add equals to also in swapping 
            // 2. find first greater element from last and break
            // Ultimately if there multiple occurence of element which is greater than idx and min from idx+1 to n-1. always replace nums[idx] with last occurence to maintain the dec order
            // It will help us to go from nlogn to n

            int temp = nums[idx];
            nums[idx] = nums[newIdx];
            nums[newIdx] = temp; 

            // Arrays.sort(nums,idx+1,n);
            reverse(nums,idx+1,n-1);
        }
    }
}