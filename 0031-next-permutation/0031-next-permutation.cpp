class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for(int i = n-1; i > 0; i--){
            if(nums[i-1] < nums[i]){idx = i-1;break;}
        }
        // cout << idx << endl;
        if(idx == -1){
            reverse(nums.begin(),nums.end());
        }else{
            int j = n-1;
            while(j > idx){
                if(nums[j] > nums[idx]){
                    swap(nums[j],nums[idx]);
                    sort(nums.begin()+idx+1,nums.end());
                    break;
                }
                j--;
            }
        }
    }
};