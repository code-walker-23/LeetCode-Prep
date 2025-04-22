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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL)return head;
        if(head->next == NULL)return NULL;

        // the below code will work only for when we have atleast two nodes in a list

        ListNode* slow = head;
        ListNode* fast = head;

        // if fast->next == NULL -> it is of odd len
        // if fast == NULL -> it is of even len
        // This algo is know as Tortoise-hare algo
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is the middle element now
        
        ListNode* temp = head;
        while(temp->next != slow){
            temp = temp->next;
        }

        // here temp is the node before middle node
        temp->next = slow->next;

        return head;
    }
};