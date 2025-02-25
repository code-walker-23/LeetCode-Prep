class Solution {
public:
    int hrsReqToEat(vector<int>& piles, int eatingSpeed) {
        long long hrs = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] % eatingSpeed != 0)
                hrs += (long long)(piles[i] / eatingSpeed + 1);
            else
                hrs += (long long)(piles[i] / eatingSpeed);
        }
        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {   
        int low = 1;
        long long high = 1e9*10;
        int minSpeed = high; // Initially, set to the largest possible value

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(hrsReqToEat(piles, mid) <= h) {
                minSpeed = mid; // Update the minimum speed
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // or minSpeed
        return low; // Return the minimum speed found
    }

    // int minEatingSpeed(vector<int>& piles, int h) {
    //     // Time -> O(piles.length*log(max of piles)) -> O(nlogn)
    //     int left = 1, right = *max_element(piles.begin(), piles.end());
    //     while (left < right) {
    //         int mid = left + (right - left) / 2;

    //         int hours = 0;
    //         // best way to calculate ceil of the piles[i]/speed -> (piles[i]+speed-1)/speed - > speed = mid
    //         for (int pile : piles) {
    //             hours += (pile + mid - 1) / mid;
    //         }

    //         if (hours <= h) {
    //             right = mid;
    //         } else {
    //             left = mid + 1;
    //         }
    //     }

    //     return left;
    // }
};
