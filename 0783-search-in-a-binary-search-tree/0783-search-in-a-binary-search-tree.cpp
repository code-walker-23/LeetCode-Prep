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
    // beat case complexity -> O(1)
    // worst case complexity -> O(height of the bst is n-1, where n is the node and in the case of left skewed tree)
    // space comp -> O(n)

    // TreeNode* searchBST(TreeNode* root, int val) {
    //    if(root ==  NULL || root -> val == val)return root;
    //    // optimaztion  
    //    if(root->val < val) 
    //        return searchBST(root -> right,val);
    //     return searchBST(root -> left,val);

    // }

    // iterative
    // time complexity will be same of the recursive
    // space -> O(1)
    TreeNode* searchBST(TreeNode* root, int val) {

       while(root != NULL){
        if(root -> val == val)return root;
        if(root -> val < val) root = root->right;
        else root = root -> left;
       }

       return NULL;
    }
};