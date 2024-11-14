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
    ListNode* middleNode(ListNode* head) {
        // naive solution
        // int length = 1;
        // ListNode* temp = head;

        // while(temp->next != NULL){
        //     temp = temp->next;
        //     length++;
        // }
        // cout << length << endl;

        // int middle = length/2+1;
        // temp = head;
        // int currPos = 1;
        // // when curr position becomes equals to middle it loops break
        // while(currPos < middle){
        //     temp = temp->next;
        //     currPos++;
        // }
        // return temp;

        if(head->next == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // that means it has even length then we have to return the second largest
        if(fast != NULL){
            return slow->next;
        }
        return slow;

    }
};