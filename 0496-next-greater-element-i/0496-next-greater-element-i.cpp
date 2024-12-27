class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // using the concept of monotonic stack to find nums2 NGE
        // monotonic stack
        // O(n) time->(nums1.size() + nums2.size())
        // space O(nums1.size() + 2*nums2.size())
        stack<int>s;
        int n = nums2.size();
        map<int,int>nge;
        
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && s.top() <= nums2[i]){
                s.pop();
            }
            if(s.empty())nge[nums2[i]] = -1;
            else nge[nums2[i]] = s.top();
            s.push(nums2[i]);
        }

        vector<int>ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++)ans[i] = nge[nums1[i]];

        return ans;
    }
};







        // /// brute force -> O(n*m*m)
        // vector<int> ans(nums1.size(),-1);

        // for(int i = 0; i < nums1.size(); i++){
        //     int el = nums1[i];
        //     for(int j = 0; j < nums2.size(); j++){
        //         if(el == nums2[j]){
        //             for(int k = j+1; k < nums2.size(); k++){
        //                 if(nums2[k] > nums2[j]){
        //                     ans[i] = nums2[k]; break;
        //                 }
        //             }
        //         }
        //     }
        // }

        // return ans;

        // Time -> O(n*m)
        // Sapce -> (n+n*m);
        //  this will be the bad approach
        // stack<int>s;
        // for(int i = 0; i < nums2.size(); i++)s.push(nums2[i]);

        // vector<int> ans(nums1.size(),-1);
        
        // for(int i = 0; i < nums1.size(); i++){
        //     int el = nums1[i];
        //     int nxtGreater = -1;
        //     stack<int>dummy = s;

        //     while(!dummy.empty() && dummy.top() != el){
        //         if(dummy.top() > el)nxtGreater = dummy.top();
        //         dummy.pop();
        //     }

        //     if(!dummy.empty() && nxtGreater != -1)ans[i] = nxtGreater;
        // }

        // return ans;
