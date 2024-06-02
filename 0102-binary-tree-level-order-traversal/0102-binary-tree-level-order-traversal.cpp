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
        if(root == NULL)return{};

        queue<TreeNode*>q;
        q.push(root);

        vector<vector<int>> Traversal;

        while(!q.empty()){

            int size = q.size();
            vector<int>level;

            for(int i = 0; i < size; i++){

                TreeNode* parent = q.front();
                q.pop();

                level.push_back(parent->val);

                TreeNode* leftChild = parent->left;
                TreeNode* rightChild = parent->right;

                if(leftChild != NULL)
                    q.push(leftChild);

                if(rightChild != NULL)
                    q.push(rightChild);
            }

            Traversal.push_back(level);
        }

        return Traversal;

    }
};