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
    // bool isValidBST(TreeNode* root) {
    //     if(root == NULL)return true;

    //     int parent = root->val;
    //     bool leftNode = true;
    //     bool rightNode = true;
    //     bool isLeftChildValid = true;
    //     bool isRightChildValid = true;

    //     if(root->left){
    //         int leftChild = root->left->val;
    //         if(leftChild >= parent)leftNode = false;
    //     }
    //     if(root->right){
    //         int rightChild = root->right->val;
    //         if(rightChild <= parent) rightNode = false;

    //     }

    //     if(leftNode && rightNode){
    //         isLeftChildValid = isValidBST(root->left);
    //         isRightChildValid = isValidBST(root->right);
            
    //         return (isLeftChildValid && isRightChildValid);
    //     }

    //     return false;
    // }

    void inorderTraversal(TreeNode* root,vector<int>&v){
        if(root == NULL)return;

        inorderTraversal(root->left,v);
        v.push_back(root->val);
        inorderTraversal(root->right,v);

    }

    bool isValidBST(TreeNode* root) {
        vector<int> v;

        inorderTraversal(root,v);

        for(int i = 0; i < v.size()-1; i++){
            if(v[i] >= v[i+1])return false;
        }

        return true;
    }
};