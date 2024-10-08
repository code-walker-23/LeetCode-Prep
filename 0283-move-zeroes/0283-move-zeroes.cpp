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

        // 2nd Sol Time -> O(n^2) when all are zeroes and Space -> O(1)
        // int count = 0;
        // for(int i = 0; i < n; i++){
        //     if(nums[i] == 0){
        //         count++;
        //     }
        // }
        
        // if(count == n || count == 0)return;

        // for(int i = 1; i <= count; i++){
        //     for(int j = 0; j < n-1; j++){
        //         if(nums[j] == 0 and nums[j+1] != 0){
        //             nums[j] = nums[j+1];
        //             nums[j+1] = 0;
        //         }
        //     }
        // }

         // 3rd Sol - >Time Complexity -> O(n^2) and Space -> O(1)
        // for(int i = 0; i < n; i++){
        //     if(nums[i] == 0){
        //         for(int j = i+1; j < n; j++){
        //             if(nums[j] != 0){
        //                 nums[i] = nums[j];
        //                 nums[j] = 0;
        //                 break;
        //             }
        //         }
        //     }
        // }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                int temp = nums[count];
                nums[count] = nums[i];
                nums[i] = temp;
                count++;
            }
        }

    }
};