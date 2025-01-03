class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        // hashing the sums
        unordered_map<int,int>mapi;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum == k)count++;
            count = count + mapi[sum-k];
            mapi[sum]++;
        }

        return count;
    }
};