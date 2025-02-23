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
        // This Moore's Voting Algorithm
        // If the majority element is there then it must be in majority in some portion of the array
        int n = nums.size();
        int count = 0;
        int element;

        for(int i = 0; i < n; i++){
            if(count == 0){
                element = nums[i];
                count = 1;
            }
            else if(nums[i] == element)count++;
            else count--;

        }
        return element;
    }
};