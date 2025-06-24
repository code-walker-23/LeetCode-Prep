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
 // Application of Diameter Ques. 
class Solution {
    int ans = Integer.MIN_VALUE;
    // this function will find the path having max sum from any node to leaf node that maximized the sum
    public int pathSum(TreeNode root){
        if(root == null)return 0;

        // it will return max sum of values from left node to leaf node
        int left = pathSum(root.left);
        int right = pathSum(root.right);
        // we are actually trying to find the root of non-empty path that has max-path sum
        // so we can have left sum  as neg or pos
        // so we can have right sum as neg or pos
        // root is manadatory to consider
        
        // left = -ve
        ans = Math.max(ans,right+root.val);
        // right = -ve
        ans = Math.max(ans,left+root.val);
        // if both are -ve
        ans = Math.max(ans,root.val);
        // if both are +ve
        ans = Math.max(ans,left+right+root.val);

        // it will return max sum of values of node from current root node to leaf node(that maximizes the sum of node values)
        if(left < 0 && right < 0)return root.val;
        return Math.max(left,right) + root.val;
    }
    public int maxPathSum(TreeNode root) {
        pathSum(root);
        return ans;
    }
}