/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
 // Inorder to get the direct height we need to capture the leaf node at the base case
 // if(root == null)return 0; and then if(root.left == null && root.right == null)return 0;
 // Otherwise calculate maxDepth and reduce by one to find the no of edges
class Solution {
    boolean isTreeBalanced = true;
    public int maxDepth(TreeNode root){
        if(root == null)return 0;

        int maxDepthLeftSubtree = maxDepth(root.left);
        int maxDepthRightSubtree = maxDepth(root.right);

        if(Math.abs(maxDepthLeftSubtree-maxDepthRightSubtree) > 1){
            isTreeBalanced = false;
        }

        return Math.max(maxDepthRightSubtree,maxDepthLeftSubtree) + 1;
    }
    public boolean isBalanced(TreeNode root) {
        // no use of return value just call
        maxDepth(root);

        return isTreeBalanced;
    }
}