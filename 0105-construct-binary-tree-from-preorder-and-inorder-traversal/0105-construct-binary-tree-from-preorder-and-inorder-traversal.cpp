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
    TreeNode* constructBinaryTree(int startPre,int endPre,vector<int>&preorder,int startIn,int endIn, vector<int>&inorder,map<int,int>&mapIn){
        // base case
        if(startIn > endIn)return NULL;

        int rootVal = preorder[startPre];
        int rootIdx = mapIn[rootVal];

        TreeNode* root = new TreeNode(rootVal);

        // elements on left side of root;
        int numsLeft = rootIdx-startIn;

        // left subtree
        root->left = constructBinaryTree(startPre+1,startPre+numsLeft,preorder,startIn,rootIdx-1,inorder,mapIn);
        //right subtree
        root->right = constructBinaryTree(numsLeft+startPre+1,endPre,preorder,rootIdx+1,endIn,inorder,mapIn);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       // hashing of inorder
        map<int,int> mapIn;
        for(int i = 0; i < inorder.size(); i++){
            mapIn[inorder[i]] = i;
        }

        // returning the root
       return constructBinaryTree(0,preorder.size()-1,preorder,0,inorder.size()-1,inorder,mapIn);

       
    }
};