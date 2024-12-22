class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecOnes = 0;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count++;
            }else{
                maxConsecOnes = max(maxConsecOnes,count);
                count = 0;
            }
        }
        if(count)
            maxConsecOnes = max(maxConsecOnes,count);
        return maxConsecOnes;
    }
};