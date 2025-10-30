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
    int length(ListNode* head){
        int l = 0;
        while(head){
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = length(head)-n+1;
        if(k == 1){
            head = head->next;
            return head;
        }
        int p = 1;
        ListNode* temp = head;
        while(p < k-1){
            p++;
            temp = temp->next;
        }
        ListNode* nxt = temp->next->next;
        temp->next = nxt;
        return head;
    }
};