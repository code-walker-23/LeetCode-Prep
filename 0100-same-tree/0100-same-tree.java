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
 // O(n)
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null || q == null)return (p == q);// this one is enough
        // if(p == null && q != null)return false;
        // if(p != null && q == null)return false;
        // if(p == null && q == null)return true;
        // if(p.val != q.val)return false;

        return (p.val == q.val && isSameTree(p.left,q.left) && isSameTree(p.right,q.right));
    }
}