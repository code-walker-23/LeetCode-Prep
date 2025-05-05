class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // // brute force
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // int maxi = 0;

        // // for(int i = 0; i < n; i++){
        // //     int op = k;
        // //     int cnt = 1;
        // //     // we have sorted the array we can use now BS to avoid tle
        // //     for(int j = i-1; j >= 0; j--){
        // //         if((nums[i]-nums[j]) > op)break;
        // //         op -= (nums[i]-nums[j]);
        // //         cnt++;
        // //     }
        // //     maxi = max(maxi,cnt);
        // // } 

        // long long prefix_sum[n];
        // prefix_sum[0] = nums[0];
        // for(int i = 1; i < n; i++)prefix_sum[i] = nums[i] + prefix_sum[i-1];

        // // for(int i = 0; i < n; i++){
        // //     int op = k;
        // //     int low = 0;
        // //     int high = i;
        // //     int cnt = 0;

        // //     while(low <= high){
        // //         int mid = (low+high)/2;
        // //         int totalOp = ((high-mid+1)*nums[i]) - (prefix_sum[high]-prefix_sum[mid]+nums[mid]);

        // //         if(totalOp > op)low = mid+1;
        // //         else {
        // //             high = mid-1;
        // //             op -= totalOp;
        // //             cnt += (high-mid+1);
        // //         } 
        // //     }

        // //     maxi = max(maxi,cnt);
        // // }
        // for (int i = 0; i < n; i++) {
        //     int low = 0, high = i;
        //     int best = i;

        //     while (low <= high) {
        //         int mid = (low + high) / 2;

        //         // cost to make nums[mid..i] equal to nums[i]
        //         long long elements = i - mid + 1;
        //         long long requiredSum = elements * nums[i];
        //         long long actualSum = prefix_sum[i] - (mid > 0 ? prefix_sum[mid - 1] : 0);
        //         long long totalOp = requiredSum - actualSum;

        //         if (totalOp <= k) {
        //             best = mid;           // this range is valid
        //             high = mid - 1;       // try to expand left
        //         } else {
        //             low = mid + 1;        // too expensive, try a smaller segment
        //         }
        //     }

        //     int cnt = i - best + 1;
        //     maxi = max(maxi, cnt);
        // }

        // return maxi; 

        // sliding window approach
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = 0;
        long long currSum = nums[0];
        int maxi = 1;

        while(r < n){
            long long orgSum = (r-l+1)*1LL*nums[r];
            long long ops = orgSum-currSum;

            if(ops <= k){
                maxi = max(maxi,(r-l+1));
                r++;
                if(r == n)break;
                currSum += nums[r];
            }
            else{
                currSum -= nums[l];
                l++;
            } 
        }

        return maxi;
    }
};