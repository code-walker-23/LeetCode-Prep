class Solution {
public:
    // bool isSorted(vector<int> arr){
    //     for(int i = 0; i < arr.size()-1; i++){
    //         if(arr[i] > arr[i+1]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // bool check(vector<int>& nums) {
    //     int n = nums.size();
    //     int rotationNumber = 0;
    //     int first = nums[0];
        
    //     for(int i = n-1; i >=2; i--){
    //         if(first > nums[i]){
    //             if(nums[i] == nums[i-1]){
    //                 i--;
    //             }
    //             rotationNumber++;
    //         }
    //         else{
    //             break;
    //         }
    //     }

    //     vector<int> original(n);
    //     for(int i = 0; i < n; i++){
    //         original[(i+rotationNumber)%n] = nums[i];
    //     }

    //     return isSorted(original);

    // }

    bool check(vector<int>& nums) {
	    int n = nums.size();
	    int count = 0;

        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                count++;
            }
        }

        if(count == 0 || count == 1 && nums[0] >= nums[n-1]){
            return true;
        }

        return false;

    }
};