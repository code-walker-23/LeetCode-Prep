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
class Solution {
    public int maxDepth(TreeNode root) {
        // for recursive it is traversing each node O(n) -> Ultimately each node will visit
        // if(root == null)return 0;

        // int maxDepthLeft = maxDepth(root.left);
        // int maxDepthRight = maxDepth(root.right);

        // return Math.max(maxDepthLeft,maxDepthRight) + 1;
        if(root == null)return 0;
        // Time Complexity -> assume Complete binary tree and level is h -> 2^0 + 2^1+ 2^2 + ....+ 2^h = gp = a*(r^n -1)/(r-1) = 1*(2^(h+1) -1)/(2-1)
        // Total node will be 2^(h+1)-1 => O(2^h) => as height increase -> nodes will increase and complexity will increase
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int level = 0;

        while(!q.isEmpty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode front = q.poll();

                if(front.left != null){
                    q.offer(front.left);
                }
                if(front.right != null){
                    q.offer(front.right);
                } 
            }

            if(!q.isEmpty())level++; // it will give height that is no of edges in longest path from the root to leaf;
        }
        // we need to add 1 in-order to find the no of nodes
        return level+1;
    }
}