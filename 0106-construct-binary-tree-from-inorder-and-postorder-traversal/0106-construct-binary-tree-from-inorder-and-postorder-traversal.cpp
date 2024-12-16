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
// Always use by reference to avoid memory limit exceeded whether it is necessary or not
    TreeNode* constructBinaryTree(int startIn,int endIn,vector<int>&inorder,int startPost,int endPost,vector<int>&postorder,map<int,int>&mapIn){
        // base case
        // endPost > startPost but before this it will hit below case
        if(startIn > endIn)return NULL;

        // taking the root -> PostOrder -> Left -> Right -> Root
        int rootVal = postorder[startPost];
        TreeNode* root = new TreeNode(rootVal);
        // index of root in inorder
        int rootIdx = mapIn[rootVal];

        // element to the right of root

        int numsRight = endIn-rootIdx;

        // contructing left and right as well recursively
        root->left = constructBinaryTree(startIn,rootIdx-1,inorder,startPost-numsRight-1,endPost,postorder,mapIn);
        root->right = constructBinaryTree(rootIdx+1,endIn,inorder,startPost-1,startPost-numsRight,postorder,mapIn);

        // returning the root
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mapIn;
        for(int i = 0; i < inorder.size(); i++)mapIn[inorder[i]] = i;

        return constructBinaryTree(0,inorder.size()-1,inorder,postorder.size()-1,0,postorder,mapIn);
    }
};