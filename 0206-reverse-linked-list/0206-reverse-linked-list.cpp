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
    void reverseLL(ListNode* &prev,ListNode* curr,ListNode* &newHead){
        if(curr == NULL){
            newHead = prev;
            return;
        }
        ListNode* nxt = curr->next;
        curr->next = prev;
        reverseLL(curr,nxt,newHead);
    }
    ListNode* reverseList(ListNode* head) {
        // we will handle all edge cases
        // ListNode* prev = NULL;
        // ListNode* curr = head;

        // while(curr != NULL){
        //     ListNode* nxt = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nxt;
        // }
        // return prev;

        // recursive approach

        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* newHead;

        reverseLL(prev,curr,newHead);
        return newHead;

    }
};