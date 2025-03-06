// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* middle(ListNode* low, ListNode* high) {
//         ListNode* slow = low;
//         ListNode* fast = low;

//         while (fast != high && fast->next != high) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }

//     void merge(ListNode* low, ListNode* mid, ListNode* high) {
//         ListNode* dummy = new ListNode();
//         ListNode* temp = dummy;
//         ListNode* i = low;
//         ListNode* j = mid->next;

//         while (i != mid->next && j != high->next) {
//             ListNode* newNode = new ListNode();
//             if (i->val < j->val) {
//                 newNode->val = i->val;
//                 temp->next = newNode;
//                 temp = temp->next;
//                 i = i->next;
//             } else {
//                 newNode->val = j->val;
//                 temp->next = newNode;
//                 temp = temp->next;
//                 j = j->next;
//             }
//         }

//         while (i != mid->next) {
//             ListNode* newNode = new ListNode(i->val);
//             temp->next = newNode;
//             temp = temp->next;
//             i = i->next;
//         }
//         while (j != high->next) {
//             ListNode* newNode = new ListNode(j->val);
//             temp->next = newNode;
//             temp = temp->next;
//             j = j->next;
//         }

//         ListNode* start = dummy->next;
//         ListNode* s = low;
//         while (start) {
//             low->val = start->val;
//             start = start->next;
//             low = low->next;
//         }
//     }

//     void mergeSort(ListNode* low, ListNode* high) {
//         if (low == high) return; 

//         ListNode* mid = middle(low, high);
//         mergeSort(low, mid);
//         mergeSort(mid->next, high);
//         merge(low, mid, high);
//     }

//     ListNode* sortList(ListNode* head) {
//         if (head == NULL) return head; 

//         ListNode* low = head;
//         ListNode* high = head;
//         while (high->next != NULL) high = high->next;

//         mergeSort(low, high);
//         return low;
//     }
// };


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* head;
        if(list1->val < list2->val) {
            head = list1;
            head->next = mergeTwoSortedLists(list1->next, list2);
        } else {
            head = list2;
            head->next = mergeTwoSortedLists(list1, list2->next);
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            if(slow != fast) {
                slow = slow->next;
            }
            fast = fast->next->next;
            
        }
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        ListNode* left = sortList(slow);
        ListNode* right = sortList(fast);
        return mergeTwoSortedLists(left, right);
    }
};