class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long op = 1;
        for(int i = 0; i < n; i++){
            op += llabs(nums1[i]-nums2[i]);
        }
        int minOp = INT_MAX;
        for(int i = 0; i < n; i++){
            int l = min(nums1[i],nums2[i]);
            int h = max(nums1[i],nums2[i]);
            if(nums2[n] >= l && nums2[n] <= h)return op;
            else minOp = min(minOp,min(abs(nums2[n]-l),abs(nums2[n]-h)));
        }
        return op+minOp;
    }
};