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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderTraversal;
        if(root == NULL)return levelOrderTraversal;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i = 0; i < size; i++){
                TreeNode* front = q.front();
                q.pop();
                
                level.push_back(front->val);

                TreeNode* left = front->left;
                TreeNode* right = front->right;

                if(left)q.push(left);
                if(right)q.push(right);
            }
            levelOrderTraversal.push_back(level);
        }

        for(int i = 1; i < levelOrderTraversal.size(); i+=2){
            reverse(levelOrderTraversal[i].begin(),levelOrderTraversal[i].end());
        }

        return levelOrderTraversal;
    }
};