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
// Time Complexity -> O(H) -> H is height of bst , max H will be in left or right skewed bst ,H = n-1, n is number of nodes and element to be inserted is min or max in the whole bst   
// iterative -> Space -> O(1)
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     TreeNode* newNode = new TreeNode(val);
    //     TreeNode* dummyRoot = root;
    //     if(root == NULL) return newNode;

    //     while(true){
    //         if(dummyRoot->val < val){
    //             if(dummyRoot->right == NULL){
    //                 dummyRoot->right = newNode;
    //                 break;
    //             }else{
    //                 dummyRoot = dummyRoot->right;
    //             }
    //         }else{
    //             if(dummyRoot->left == NULL){
    //                 dummyRoot->left = newNode;
    //                 break; 
    //             }else{
    //                 dummyRoot = dummyRoot->left;
    //             }
    //         }
    //     }

    //     return root;
    // }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       if(root == NULL) return new TreeNode(val);

       if(root->val < val) root->right = insertIntoBST(root->right,val);
       else root->left = insertIntoBST(root->left,val);

       return root;
    }
};