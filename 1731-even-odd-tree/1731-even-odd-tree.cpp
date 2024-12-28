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
// Time -> O(H+2*N) -> we can optimize this to O(H+N)
// Sapce -> (queue+vector)
    // bool isEvenOddTree(TreeNode* root) {
    //     queue<TreeNode*>q;
    //     q.push(root);
    //     int level = 0;

    //     while(!q.empty()){
    //         int size = q.size();
    //         vector<int> levelNodes;

    //         for(int i = 0; i < size; i++){
    //             TreeNode* node = q.front();
    //             q.pop();

    //             levelNodes.push_back(node->val);

    //             TreeNode* left = node->left;
    //             TreeNode* right = node->right;

    //             if(left)q.push(left);
    //             if(right)q.push(right);
    //         }

    //         if(level%2){
    //                 // if level is odd
    //                 // strictly decreasing even numbers
    //             if(levelNodes.size() == 1 && levelNodes[0]%2)return false;
    //             for(int i = 0; i < levelNodes.size()-1; i++){
    //                 if(levelNodes[i]%2 || levelNodes[i+1]%2 || (levelNodes[i] <= levelNodes[i+1]))return false;
    //             }
    //         }else{
    //             // if level is even
    //             // strictly increasing odd numbers
    //             if(levelNodes.size() == 1 && (levelNodes[0]%2 == 0))return false;
    //             for(int i = 0; i < levelNodes.size()-1; i++){ 
    //                 if(levelNodes[i]%2 == 0 || levelNodes[i+1]%2 == 0 || (levelNodes[i] >= levelNodes[i+1]))return false;
    //             }
    //         }

    //         level++;
    //     }
    //     return true;
    // }

// Time -> O(H+N) = O(N) because H<=N
// Space -> O(queue)
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            int prevVal = -1;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                int val = node->val;
                // when we will be having only one node in level
                if(prevVal == -1 && level%2){
                    if(val%2)return false;
                }
                else if(prevVal == -1 && level%2 == 0){
                    if(val%2 == 0)return false;
                }
                else{
                    if(level%2 && (prevVal%2 || val%2 || prevVal <= val))return false;
                    else if(level%2 == 0 && (prevVal%2 == 0 || val%2 == 0 || prevVal >= val))return false;
                }
                prevVal = val;

                TreeNode* left = node->left;
                TreeNode* right = node->right;

                if(left)q.push(left);
                if(right)q.push(right);
            }

            level++;
        }
        return true;
    }
};