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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        TreeNode* dummyRoot = root;
        if(root == NULL) return newNode;
        
        while(true){
            if(dummyRoot->val < val){
                if(dummyRoot->right == NULL){
                    dummyRoot->right = newNode;
                    break;
                }else{
                    dummyRoot = dummyRoot->right;
                }
            }else{
                if(dummyRoot->left == NULL){
                    dummyRoot->left = newNode;
                    break; 
                }else{
                    dummyRoot = dummyRoot->left;
                }
            }
        }

        return root;
    }
};