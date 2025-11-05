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
            else{
                // if(nums1[i] < nums2[i]){
                //     int ex = 0;
                //     if(nums2[n] < nums1[i]){
                //         ex = (nums2[i]-nums2[n]) + (nums1[i]-nums2[n]);
                //     }else{
                //         ex = (nums2[n]-nums1[i]) + (nums2[n]-nums2[i]);
                //     }
                //     minOp = min(minOp,ex);
                // }else{
                //     int ex = 0;
                //     if(nums2[n] > nums1[i]){
                //         ex = (nums2[n]-nums1[i]) + (nums2[n]-nums2[i]);
                //     }else{
                //         ex = (nums2[n]-nums2[i]) + (nums2[n]-nums1[i]);
                //     }
                //     minOp = min(minOp,ex);
                // }
                if(nums2[n] < l){
                    minOp = min(minOp,abs(l-nums2[n]));
                }else{
                    minOp = min(minOp,abs(h-nums2[n]));
                }
            }
        }
        return op+minOp;
    }
};