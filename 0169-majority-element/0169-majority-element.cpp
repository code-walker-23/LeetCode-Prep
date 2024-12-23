class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //brute force will be O(n) both time and space
        // int n = nums.size();
        // unordered_map<int,int> mapi;

        // for(int i = 0; i < n; i++)mapi[nums[i]]++;
        // int ans = 0;
        // for(auto p : mapi){
        //     if(p.second > n/2){
        //         ans = p.first;
        //         break;
        //     }
        // }
        // return ans;

        // Better in constant space

        int n = nums.size();
        int count = 1;
        int element = nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] == element)count++;
            else count--;

            if(count == 0){
                element = nums[i+1];
            }
        }
        return element;
    }
};