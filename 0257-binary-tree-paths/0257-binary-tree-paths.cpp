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
    void allNodes(TreeNode* root,string s,vector<string>&ans){
        // when we reach to the leaf node
        if(root == NULL)return;
        s += to_string(root->val);
        
        if(root && !(root->left) && !(root->right)){
            ans.push_back(s);
            return;
        }
        
        s += "->";
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        allNodes(root->left,s,ans);
        allNodes(root->right,s,ans);
    
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans; 
        string s;

        allNodes(root,s,ans);
        return ans;
    }
};