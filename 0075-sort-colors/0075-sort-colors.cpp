class Solution {
public:
    void sortColors(vector<int>& nums) {
        // most brute force will be sort the array in O(nlogn).
        // sort(nums.begin(),nums.end());
        // we will be using the dutch national flag algorithm to get optimized soltuion in O(n)
        // we have to do it in constant space because this is the in-place algo

        // better will be taking the count of the O,1 and 2 and inserting into the nums according to their respective count  0 to 2 -> O(2n) time and space->O(1)
        // int n = nums.size();
        // int count0 = 0;
        // int count1 = 0;
        // int count2 = 0;
        // // O(n)
        // for(int i = 0; i < n; i++){
        //     if(nums[i] == 0)count0++;
        //     else if(nums[i] == 1)count1++;
        //     else count2++;
        // }
        // // O(n)
        // for(int i = 0; i < n; i++){
        //     if(i < count0)nums[i] = 0;
        //     else if(i < count0+count1)nums[i] = 1;
        //     else nums[i] = 2;
        // }


        // optimal will dutch algo in Time->O(n) and Space->O(1)

        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;

        while(mid <= high){
            if(nums[mid] == 1){
                mid++;
            }else if(nums[mid] == 0){
                int temp = nums[low];
                nums[low] = 0;
                nums[mid] = temp;
                low++; mid++;
            }else{
                int temp = nums[high];
                nums[high] = 2;
                nums[mid] = temp;
                high--;
            }
        } 

    }
};