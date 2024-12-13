/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
//Time Complexity -> O(height) -> O(n , when we have left or right skewwed tree)
// Best -> when the tree is complete -> O(logn)
// Space Compelxity -> O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(((p->val < root->val) && (q->val < root->val))){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(((p->val > root->val)&&(q->val > root->val))){
            return lowestCommonAncestor(root->right,p,q);
        }
        // when there is point of split -> either one them will be lesser than root and one will be greater than root or one of them will be equal to root
        return root;
    }
};