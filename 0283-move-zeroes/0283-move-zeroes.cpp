class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Naive Approach Time -> O(n) and Space -> O(n)=This is the issue
        int n = nums.size();
        // int count = 0;
        // vector<int> res;
        // for(int i = 0; i < n; i++){
        //     if(nums[i] == 0){
        //         count++;
        //     }
        //     else{
        //         res.push_back(nums[i]);
        //     }
        // }

        // for(int i = n-count; i < n; i++){
        //     res.push_back(0);
        // }

        // for(int i = 0; i < n; i++){
        //     nums[i] = res[i];
        // }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                count++;
            }
        }
        
        if(count == n)return;

        for(int i = 1; i <= count; i++){
            for(int j = 0; j < n-1; j++){
                if(nums[j] == 0 and nums[j+1] != 0){
                    nums[j] = nums[j+1];
                    nums[j+1] = 0;
                }
            }
        }

    }
};