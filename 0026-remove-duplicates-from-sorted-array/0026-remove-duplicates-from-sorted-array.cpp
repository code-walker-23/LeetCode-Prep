class Solution {
public:

    int removeDuplicates(vector<int>& nums) {
    // out of place algo
    //    int n = nums.size();
    //    vector<int> expectedNums;
    //    expectedNums.push_back(nums[0]);
    //    for(int i = 0; i < n-1; i++){
    //         if(nums[i] != nums[i+1]){
    //             expectedNums.push_back(nums[i+1]);
    //         }
    //    }
    //    for(int i = 0; i < expectedNums.size(); i++){
    //         nums[i] = expectedNums[i];
    //    }
    //    return expectedNums.size();



    // In-place algo but O(n^2) 
    // 	int n = nums.size();
    //     int count = 1;
    //     int last = nums[0];
        
    //     for(int i = 1; i < n; i++){
    //         if(nums[i] == last){
    //             nums[i] = -101;
    //         }else{
    //             last = nums[i];
    //             count++;
    //         }
    //     }

    //     for(int i = 2; i < n; i++){
    //         if(nums[i] != -101){
    //             for(int j = 1; j < i; j++){
    //                 if(nums[j] == -101){
    //                     swap(nums[j],nums[i]);
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return count;
    // 

        // Out-of-pace and O(n)
        // int n = nums.size();
        // int temp[n];
        // temp[0] = nums[0];
        // int res = 1;

        // for(int i = 1; i < n; i++){
        //     if(temp[res-1] != nums[i]){
        //         temp[res] = nums[i];
        //         res++;
        //     }
        // }
        // for(int i = 0; i < n; i++){
        //     nums[i] = temp[i];
        // }
        // return res;

        int n = nums.size();
        int res = 1;

        for(int i = 1; i < n; i++){
            if(nums[res-1] != nums[i]){
                nums[res] = nums[i];
                res++;
            }
        }
        
        return res; // it takes the sub-array from on the basis of the size of the distinct elements 
    }
};