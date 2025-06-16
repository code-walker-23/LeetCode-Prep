class Solution {
    public static void rearrange(int nums[]) {
        // code here
        int n = nums.length;
        int[] dummy = new int[n];
        
        for(int i = 0; i < n; i++)dummy[i] = nums[i];
        
        Arrays.sort(dummy);
        int low = 0;
        int high = n-1;
        int i = 0;
        
        while(low < high){
            nums[i++] = dummy[high];
            nums[i++] = dummy[low];
            low++; high--;
        }
        
        if(n%2 != 0){
            nums[i] = dummy[low];
        }
        
    }
}
