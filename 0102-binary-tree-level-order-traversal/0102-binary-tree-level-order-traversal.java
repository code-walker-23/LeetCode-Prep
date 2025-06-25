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
 // Time Complexity -> (n + k*h) where n is no of nodes and k is avg size of each level and h is height
 // Space Complexity -> (n)
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> traversal = new ArrayList<>();
        if(root == null)return traversal;

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while(!q.isEmpty()){
            int size = q.size();
            List<Integer> level = new ArrayList<>();

            for(int i = 0; i < size; i++){
                TreeNode front = q.poll();
                level.add(front.val);

                if(front.left != null){
                    q.offer(front.left);
                }
                if(front.right != null){
                    q.offer(front.right);
                }
            }

            traversal.add(level);
        }

        return traversal;
    }
}