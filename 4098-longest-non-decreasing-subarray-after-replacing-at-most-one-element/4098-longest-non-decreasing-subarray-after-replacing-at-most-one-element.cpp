class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return n;
        
        vector<int>lft(n,1);
        vector<int>rgt(n,1);

        for(int i = 1; i < n; i++){
            if(nums[i] >= nums[i-1])lft[i] = lft[i-1]+1;
        }
        for(int i = n-2; i >= 0; i--){
            if(nums[i] <= nums[i+1])rgt[i] = rgt[i+1]+1;
        }
        
        int maxi = 1;
        maxi = max(maxi, 1 + (n > 1 ? rgt[1] : 0));
        maxi = max(maxi, lft[n-2] + 1);
        
        for(int i = 1; i < n-1; i++){
            if(nums[i-1] <= nums[i+1]){
                maxi = max(maxi,lft[i-1]+rgt[i+1]+1);
            }else{
                maxi = max(maxi,lft[i-1]+1);
                maxi = max(maxi,rgt[i+1]+1);
            }
        }
        
        return maxi;
    }
};