class Solution {
public:
    bool cmp(pair<string, int>& a,pair<string, int>& b){ 
        return a.second < b.second; 
    } 
// brute force , we need to do some pre computation
    // int disHelper(vector<int>v,int idx,int size){
    //     int n = v.size();
    //     int minDis = INT_MAX;

    //     for(int i = 0; i < n; i++){
    //         if(v[i] == idx)continue;
    //         int straightDis = abs(v[i]-idx);
    //         int cirDis = size-straightDis;
    //         minDis = min(minDis,min(straightDis,cirDis));
    //     }

    //     return minDis;
    // }
    // const is necessary to reduce tle
    int disHelper(const vector<int>&v,int q,int size){
        int n = v.size();
        int minDis = INT_MAX;

        int low = 0;
        int high = n-1;
        
        int mid = (low+high)/2;
        while(low <= high){
            if(v[mid] == q)break;
            if(v[mid] > q)high = mid-1;
            else low = mid+1;
            mid = (low+high)/2;
        }

        int leftDis = INT_MAX;
        int rightDis = INT_MAX;

        if(mid-1 >= 0)leftDis = min(q-v[mid-1],size-q+v[mid-1]);
        else leftDis = size-v[n-1]+q;
        if(mid+1 < n)rightDis = min(v[mid+1]-q,size-v[mid+1]+q);
        else rightDis = v[0]+size-q;

        return min(leftDis,rightDis);
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int, vector<int>> mapi;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            mapi[nums[i]].push_back(i);
        }

        for (auto& [key, v] : mapi) {
            sort(v.begin(), v.end());
        }

        for (int q : queries) {
            const vector<int>& v = mapi[nums[q]];
            int minDis = (v.size() > 1) ? disHelper(v, q, nums.size()) : -1;
            res.push_back(minDis);
        }

        return res;
    }
};