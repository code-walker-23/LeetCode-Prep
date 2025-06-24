/*
class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
 */

class Solution {
    // Function to find the height of a binary tree.
    int maxDepth(Node root){
        if(root == null)return 0;
        
        int depthLeftSubtree = maxDepth(root.left);
        int depthRightSubtree = maxDepth(root.right);
        
        return Math.max(depthLeftSubtree,depthRightSubtree) + 1;
    }
    int height(Node node) {
        return maxDepth(node)-1;
    }
}