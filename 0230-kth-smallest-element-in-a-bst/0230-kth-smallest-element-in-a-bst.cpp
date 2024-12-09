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
    // Brute Solution -> Take dfs or bfs and store in the vector then O(bfs or dfs + sorting) = O(n+e+nlogn) ans space -> O(n)
    // Better
    // Time Complexity -> O(n) -> inorder Traversal 
    // Space Complexity -> O(n) -> we will try to omit this

    // Optimized
public:
    
    // void inorderTraversal(TreeNode* root, vector<int>&v){
    //     if(root == NULL)return;

    //     inorderTraversal(root->left,v);
    //     v.push_back(root->val);
    //     inorderTraversal(root->right,v);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int> v;
    //     inorderTraversal(root,v);

    //     return v[k-1];
    // }

    // optimized space->O(1)
    int ans;
    void inorderTraversal(TreeNode* root, int &k){
        if(k <= 0)return;
        if(root == NULL)return;

        inorderTraversal(root->left,k);
        k--;
        if(k == 0){
            ans = root->val;
        }
        inorderTraversal(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) { 
        inorderTraversal(root,k);

        return ans;
    }
};