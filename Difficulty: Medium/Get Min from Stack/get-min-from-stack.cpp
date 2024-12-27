//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
     void push(int val) {
        if(s.empty()){
            s.push(val);
            minEle = val;
        }
        else if(val < minEle){
            int prevMin = minEle;
            int currMin = val;

            // newVal will always less than currMin(val)
            int newVal = 2*currMin-prevMin;
            s.push(newVal);
            minEle = currMin; 
        }else{
            s.push(val);
        }
    }

    int pop() {
        if(s.empty())return -1;
        int top = s.top();
        s.pop();
        // check top is modified or not
        if(top < minEle){
            int poppedElement = minEle;
            // the popped element is the currMin so change this to prevMin
            // using the same formula
            int currMin = minEle;
            int newVal = top;
            int prevMin = 2*currMin-newVal;

            // now modified the minElement with prevMin
            minEle = prevMin;
            return poppedElement;
        }
        return top;
    }

    int getMin() {
        if(s.empty())return -1;
        return minEle; // O(1) retrieval of minimum
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends