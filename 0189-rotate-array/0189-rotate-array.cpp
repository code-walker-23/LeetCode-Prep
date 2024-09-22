class Solution {
public:
    // Time Complexity -> O(n*k) -> (n*n) beacuse 0<=k<=n  or Theta -> O(n*k)
    // Space Complexity => O(1)
    // void rotateToTheRightByOnePlace(vector<int>&arr,int n){
    //     int temp = arr[n-1];
    //     for(int i = n-2; i >= 0; i--){
    //         arr[i+1] = arr[i]; 
    //     }
    //     arr[0] = temp;
    // }

    void printNums(vector<int>arr){
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // 1st Sol
        // Time -> O(n)
        // Space -> O(n) 
        // vector<int> rotated(n);
        // for(int i = 0; i < n; i++){
        //     rotated[(i+k)%n] = nums[i];
        // }
        // for(int i = 0; i < n; i++){
        //     nums[i] = rotated[i];
        // }

        // 2nd Sol
        // for(int i = 1; i <= k%n; i++){
        //     rotateToTheRightByOnePlace(nums,n);
        // }

        // 3rd Sol
        k = k%n;
        vector<int> temp(k);
        for(int i = n-k; i < n; i++){
            temp[i-n+k] = nums[i];
        }
        printNums(temp);

        for(int i = n-k-1; i >= 0; i--){
            nums[i+k] = nums[i];
        }
        printNums(nums);

        for(int i = 0; i < k; i++){
            nums[i] = temp[i];
        }
        printNums(nums);

    }
};