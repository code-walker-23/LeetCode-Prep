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
        ListNode* curr = head;
        unordered_set<ListNode*> visited;

        while(curr != NULL){
            if(visited.find(curr) != visited.end())
                return true;
            else{    
                visited.insert(curr);
                curr = curr->next;
            }
        }

        return false;
    }
};