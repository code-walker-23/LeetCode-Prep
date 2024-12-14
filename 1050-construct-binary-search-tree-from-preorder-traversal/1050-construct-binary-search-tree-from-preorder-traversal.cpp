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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // naive approach
        TreeNode* root = new TreeNode(preorder[0]);

        // INSERTING THE ELEMENTS MANUALLY
        for(int i = 1; i < preorder.size(); i++){
            int key = preorder[i];
            
            TreeNode* temp = root;
            while(true){
                if(temp->val > key){
                    if(temp->left == NULL){
                        temp->left = new TreeNode(key);
                        break;
                    }else{
                        temp = temp->left;
                    }
                }else{
                    if(temp->right == NULL){
                        temp->right = new TreeNode(key);
                        break;
                    }else{
                        temp = temp->right;
                    }
                }
            }
        }

        return root;
    }
};