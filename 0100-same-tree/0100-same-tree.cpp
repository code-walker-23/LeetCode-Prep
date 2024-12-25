/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // // if both are null then they are identical, there is no point of difference
        // if(p == NULL && q == NULL)return true;
        // // if any one of them is null then false
        // if(p == NULL || q == NULL)return false;

        // // both are not null
        // if((p->val) != (q->val))return false;

        // return (isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));



        if(p == NULL || q == NULL)return (p == q);

        return ((p->val == q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
    }
};