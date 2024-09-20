class Solution {
public:
    bool isSorted(vector<int> arr){
        for(int i = 0; i < arr.size()-1; i++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }

    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int x = 0; x < n; x++){
            vector<int> rotated(n);
            for(int j = 0; j < n; j++){
                rotated[(j+x)%n] = nums[j];
            }
            if(isSorted(rotated)){
                return true;
            }
        }

        return false;

    }
};