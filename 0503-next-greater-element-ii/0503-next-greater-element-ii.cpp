class Solution {
public:
    // Time -> O(3*n) = O(n) it is linear
    // Space -> O(2*stack+nge) = O(3*n) = O(n)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge(n,-1);
        // stack to scan from right
        stack<int>sr;
        // stack to scan from the left
        stack<int>sl;

        // O(n)
        // storing the nums element in stack in specific order , first at the top
        for(int i = n-1; i >= 0; i--)sl.push(nums[i]);

        for(int i = n-1; i >= 0 ; i--){
            // O(n)
            while(!sr.empty() && sr.top() <= nums[i])sr.pop();
            // O(n)
            while(sr.empty() && !sl.empty() && sl.top() <= nums[i])sl.pop();
            
            if(sr.empty()){
                // we found to the left
                if(!sl.empty())nge[i] = sl.top();
                // we did not found in either sides
                else nge[i] = -1;
            }
            // we found to the right
            else nge[i] = sr.top();

            sr.push(nums[i]);
        }

        return nge;
    }
};












// class Solution {
// public:
// // Time -> O(n+n^2) = O(n^2)
// // Space -> O(stack+nge) = O(n)
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>nge(n,-1);
//         stack<int>s;

//         for(int i = n-1; i >=0 ; i--){
//             // O(n)
//             while(!s.empty() && s.top() <= nums[i])s.pop();
            
//             // O(n^2)-> when array is in decreasing order from right side, we have to got to the left
//             if(s.empty()){
//                 // we did not find next greater element to the right of the element , will shift to the left(this is    circular, starting from the next of the element to the before it occurs considered as a right )
//                 for(int j = 0; j < i; j++){
//                     if(nums[j] > nums[i]){
//                         nge[i] = nums[j];
//                         break;   
//                     }
//                 }
//             }
//             // we found to the right
//             else nge[i] = s.top();

//             s.push(nums[i]);
//         }
//         return nge;
//     }
// };