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
    TreeNode* SearchBST(TreeNode* root,int value){
        if(root == NULL)return root;
        if(root->val == value)return root;
        if(value < root->val)return SearchBST(root->left,value);
        return SearchBST(root->right,value);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
      while(root !=  NULL){
          if(root->val == val)return root;
          else if(root->val < val)root = root->right;
          else root = root->left;
      }
        return NULL;
    }
};