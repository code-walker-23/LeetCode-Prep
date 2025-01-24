class Solution {
public:
// brute force
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        int n = nums.size();

        // generating all sub-arrays
        for(int i = 0; i < n; i++){
            int product = 1;
            for(int j = i; j < n; j++){
                product *= nums[j];
                maxProduct = max(maxProduct,product);
            }
        }

        return maxProduct;
    }
};