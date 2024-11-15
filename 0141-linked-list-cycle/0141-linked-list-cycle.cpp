/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // brute force
        ListNode* prev = NULL;
        ListNode* curr = head;
        unordered_set<ListNode*> visited;
        visited.insert(curr);

        while(curr != NULL){
            prev = curr;
            curr = curr->next;
            if(curr != NULL){
                if(visited.find(curr) != visited.end())
                    return true;
                else    
                    visited.insert(curr);
            }
        }

        return false;
    }
};