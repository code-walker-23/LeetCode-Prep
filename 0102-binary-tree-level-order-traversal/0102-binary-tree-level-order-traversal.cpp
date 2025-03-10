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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // we will use the queue data structure
        vector<vector<int>> ans;
        if(root == NULL)return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>v;

            for(int i = 0; i < size; i++){
                TreeNode* front = q.front();
                q.pop();

                v.push_back(front->val);

                TreeNode* left = front->left;
                TreeNode* right = front->right;

                if(left)q.push(left);
                if(right)q.push(right);

            }

            ans.push_back(v);

        }
        return ans; 
    }
};