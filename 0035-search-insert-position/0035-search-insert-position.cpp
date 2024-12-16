class Solution {
public:
    // when target is not present , at the last iteration of the our while, when low == high == mid
    // from here there will be two cases
    // 1.) arr[mid] > target ==> high = mid-1;   ==> low > high ==> break;
    // 2.) arr[mid] < target ==> low = mid+1;    ==> low > high ==> break;
    // low will be the insert pos

    int searchInsert(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;
        int mid = -1;

        while(low <= high){
            mid = low + (high-low)/2;
            if(arr[mid] == target)return mid;

            if(arr[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;   
    }
};