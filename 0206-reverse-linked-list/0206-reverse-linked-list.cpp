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
//     ListNode* reverseLL(ListNode* prev,ListNode* curr){
//         if(curr == NULL){
//             return prev;
//         }
//         ListNode* nxt = curr->next;
//         curr->next = prev;
//         return reverseLL(curr,nxt);
//     }
//     ListNode* reverseList(ListNode* head) {
        
//         ListNode* prev = NULL;
//         ListNode* curr = head;
//         ListNode* newHead;

//         return reverseLL(prev,curr);
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
    void reverseLL(ListNode* &prev,ListNode* curr){
        if(curr == NULL){
            return;
        }
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        reverseLL(prev,nxt);
    }
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        reverseLL(prev,curr);
        return prev;
    }
};