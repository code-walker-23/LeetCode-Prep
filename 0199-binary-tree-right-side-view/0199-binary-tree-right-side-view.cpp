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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                level[i] = node->val;

                TreeNode* left = node->left;
                TreeNode* right = node->right;

                if(left)q.push(left);
                if(right)q.push(right);
            }
            // for leftside view push level[0]
            ans.push_back(level[size-1]);
        }

        return ans;
    }
};