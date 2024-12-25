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
    int maxSum(TreeNode* root,int &ans){
        if(root == NULL)return 0;

        int left = maxSum(root->left,ans);
        int right = maxSum(root->right,ans);
        
        int totalSum = root->val;
        if(left > 0)totalSum+=left;
        if(right > 0)totalSum+=right; 

        ans = max(ans,totalSum);
        if(left < 0 && right < 0)return (root->val);
        return (root->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxSum(root,ans);
        return ans;
    }
};