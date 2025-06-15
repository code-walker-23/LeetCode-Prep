class Solution {
    public int[] rearrangeArray(int[] nums) {
        // Naive Approach -> O(n) and Space -> O(2*n)
        // We can reduce the Space as well
        int n = nums.length;
        int[] pos = new int[n/2];
        int[] neg = new int[n/2];
        int i = 0,j = 0;

        for(int k = 0; k < n; k++){
            if(nums[k] > 0){
                pos[i++] = nums[k];
            }else{
                neg[j++] = nums[k];
            }
        } 

        int[] res = new int[n];
        int h = 0;

        for(i = 0; i < n/2; i++){
            res[h++] = pos[i];
            res[h++] = neg[i]; 
        }

        return res;
    }
}