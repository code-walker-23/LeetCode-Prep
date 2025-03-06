//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given linked list using Merge Sort.
    Node* mergeTwoSortedLists(Node* list1, Node* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        Node* head;
        if(list1->data < list2->data) {
            head = list1;
            head->next = mergeTwoSortedLists(list1->next, list2);
        } else {
            head = list2;
            head->next = mergeTwoSortedLists(list1, list2->next);
        }
        return head;
    }
    Node* mergeSort(Node* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;

        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL) {
            if(slow != fast) {
                slow = slow->next;
            }
            fast = fast->next->next;
            
        }
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        Node* left = mergeSort(slow);
        Node* right = mergeSort(fast);
        return mergeTwoSortedLists(left, right);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends