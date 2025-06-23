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
    List<Integer> preOrder = new ArrayList<>();
    public void dfs(TreeNode root){
        if(root == null)return;
        
        preOrder.add(root.val);
        dfs(root.left);
        dfs(root.right);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        // dfs(root);
        if(root == null)return preOrder;

        Stack<TreeNode> s = new Stack<>();
        s.push(root);

        while(!s.isEmpty()){
            TreeNode peek = s.pop();

            if(peek != null){
                preOrder.add(peek.val);
                s.push(peek.right);
                s.push(peek.left);
            }

        }
        return preOrder;
    }
}