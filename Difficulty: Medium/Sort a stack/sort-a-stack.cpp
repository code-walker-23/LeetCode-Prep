//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);

cout << "~" << "\n";
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void merge(stack<int>&s,int x){
    vector<int> arr;
    while(!s.empty()){
        int poppedElement = s.top();
        s.pop();
        arr.push_back(poppedElement);
    }
    reverse(arr.begin(),arr.end());
    arr.push_back(-1);
    int j = arr.size()-2;
    
    while(arr[j] > x && j >= 0){
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = x;
    
    for(auto el : arr){
        s.push(el);
    }
}

void sortAnStackUsingRecursion(stack<int> &s){
    if(s.size() == 0)return;

    int x = s.top();
    s.pop();
    sortAnStackUsingRecursion(s);
    merge(s,x);

}
void SortedStack :: sort()
{
   sortAnStackUsingRecursion(s);
}