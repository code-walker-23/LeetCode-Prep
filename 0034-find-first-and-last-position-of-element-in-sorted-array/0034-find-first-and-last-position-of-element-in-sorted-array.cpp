class Solution {
public:
    int firstOcc(vector<int>arr,int target){
        int low = 0;
        int high = arr.size()-1;
        int firstOccurence = -1;

        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] == target){
                firstOccurence = mid;
                high = mid-1;
            }else if(arr[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return firstOccurence;
    }
    int lastOcc(vector<int>arr,int target){
        int low = 0;
        int high = arr.size()-1;
        int lastOccurence = -1;

        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] == target){
                lastOccurence = mid;
                low = mid+1;
            }else if(arr[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return lastOccurence;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = firstOcc(nums,target);
        int last = lastOcc(nums,target);

        vector<int> ans = {first,last};

        return ans;
    }
};