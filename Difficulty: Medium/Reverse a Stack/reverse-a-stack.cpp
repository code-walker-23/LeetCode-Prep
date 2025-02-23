//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // void rev(vector<int>&arr){
    //     if(low >= high)return;
        
    //     int temp = arr[low];
    //     arr[low] = arr[high];
    //     arr[high] = temp;
    //     low++,high--;
    //     rev(low,high,arr);
        
    // }
    void Reverse(stack<int> &St){
        vector<int> arr;
        
        while(!St.empty()){
            int x = St.top();
            St.pop();
            arr.push_back(x);
        }
        
        for(auto el : arr){
            St.push(el);
        }
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends