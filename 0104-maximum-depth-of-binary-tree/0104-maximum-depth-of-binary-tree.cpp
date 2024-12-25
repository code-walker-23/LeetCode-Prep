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
    int maxDepth(TreeNode* root) {
        if(root == NULL)return 0;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        int max1 = 1;
        int max2 = 1;

        if(left) max1 += maxDepth(left);
        if(right) max2 += maxDepth(right);

        return max(max1,max2);
    }
};