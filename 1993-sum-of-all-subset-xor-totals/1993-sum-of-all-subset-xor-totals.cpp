class Solution {
public:
    int sumXor(vector<int>&arr){
        int n = arr.size();
        int sum = 0;

        for(int i = 0; i < (1 << n); i++){
            int XOR = 0;
            for(int j = 0; j < 32; j++){
                int mask = (1 << j);
                if(i&mask)XOR ^= arr[j];
            }
            sum += XOR;
        }

        return sum;
    }
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            total |= num;
        }
        return total * (1 << (nums.size() - 1)); // O(n)
        // this 2^N 
        return sumXor(nums);
    }
};