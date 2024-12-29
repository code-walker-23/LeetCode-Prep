class Solution {
public:
// Time -> O(n) and Space-> O(1)
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax= 0;
        int rightMax = 0;
        int total = 0;
        int l = 0;
        int r = n-1;


         while(l<=r){
            if(height[l] <= height[r]){
                if(leftMax > height[l])total += (leftMax-height[l]);
                else leftMax = max(leftMax,height[l]);
                l++;
            }else{
                if(rightMax > height[r]){
                    total += (rightMax-height[r]);
                }
                else rightMax= max(rightMax,height[r]);
                r--;
            }
        }



        // while(l<=r){
        //     if(height[l] < height[r]){
        //         if(leftMax > height[l])total += (min(leftMax,height[r])-height[l]);
        //         leftMax = max(leftMax,height[l]);
        //         l++;
        //     }else if(height[l] == height[r]){
        //         if(leftMax > height[l])total += (leftMax-height[l]);
        //         leftMax = max(leftMax,height[l]);
        //         l++;
        //     }
        //     else{
        //         if(rightMax > height[r]){
        //             total += (min(rightMax,height[l])-height[r]);
        //         }
        //         rightMax= max(rightMax,height[r]);
        //         r--;
        //     }
        // }

        return total;
    }












// // Time -> O(3*n) -> we can reduce this ans also space -> O(2*n)
//     int trap(vector<int>& height) {
//         // precomputing leftmax and rightmax for every element
//         int n = height.size();
//         vector<int>leftMax(n);
//         vector<int>rightMax(n);

//         leftMax[0] = INT_MIN;
//         for(int i = 1; i < n-1; i++)leftMax[i] = max(height[i-1],leftMax[i-1]);
//         rightMax[n-1] = INT_MIN;
//         for(int i = n-2; i >= 0; i--)rightMax[i] = max(height[i+1],rightMax[i+1]);

//         // for(int i = 0; i < n; i++){
//         //     cout << height[i] << "-> leftMax = " << leftMax[i] << " and " << "rightMax = " << rightMax[i] << endl;
//         // }

//         int totalWater = 0;
//         for(int i = 1; i < n-1; i++){
//             int capacity = min(leftMax[i],rightMax[i]) - height[i];
//             if(capacity > 0)totalWater += capacity; 
//         }

//         return totalWater;
//     }
};