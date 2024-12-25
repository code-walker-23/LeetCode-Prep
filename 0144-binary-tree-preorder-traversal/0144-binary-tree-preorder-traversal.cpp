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
// iterative -> O(n)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)return {};

        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* top = s.top();
            s.pop();
            ans.push_back(top->val);

            TreeNode* left = top->left;
            TreeNode* right = top->right;
            
            if(right)s.push(right);
            if(left)s.push(left);
        }
       
        return ans;
    }
};