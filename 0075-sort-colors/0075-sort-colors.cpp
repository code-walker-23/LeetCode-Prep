class Solution {
public:
    void sortColors(vector<int>& nums) {
        // most brute force will be sort the array in O(nlogn).
        sort(nums.begin(),nums.end());
        // we will be using the dutch national flag algorithm to get optimized soltuion in O(n)
        // we have to do it in constant space because this is the in-place algo

        // better will be taking the count of the O,1 and 2 and inserting into the nums according to their respective count  0 to 2 -> O(n) sapce and time

        // optimal will dutch algo in Time->O(n) and Space->O(1) 





    }
};