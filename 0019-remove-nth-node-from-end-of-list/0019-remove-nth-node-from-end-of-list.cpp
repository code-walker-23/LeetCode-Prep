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
    int len(ListNode* head){
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL){
            count++;
            temp= temp->next;
        }

        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        cout << len(head) << endl;
        int k = len(head)-n;
        
        if (k == 0) {
            // ListNode* toDelete = head;
            head = head->next;
            // delete toDelete;
            return head;
        }

        ListNode* temp = head;
        int count = 0;

        // Traverse to the node just before the one to delete
        while (count < k - 1) {
            temp = temp->next;
            count++;
        }

        temp->next = temp->next->next;
        // delete toDelete;
        return head;
    }
};