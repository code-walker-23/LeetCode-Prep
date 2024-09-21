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
    	int n = nums.size();
        int count = 1;
        int last = nums[0];
        
        for(int i = 1; i < n; i++){
            if(nums[i] == last){
                nums[i] = -101;
            }else{
                last = nums[i];
                count++;
            }
        }

        for(int i = 2; i < n; i++){
            if(nums[i] != -101){
                for(int j = 1; j < i; j++){
                    if(nums[j] == -101){
                        swap(nums[j],nums[i]);
                        break;
                    }
                }
            }
        }
        return count;
    }

};