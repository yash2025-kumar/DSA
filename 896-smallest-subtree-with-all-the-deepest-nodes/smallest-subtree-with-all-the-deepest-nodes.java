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
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
       return dfs(root).getKey(); 
    }

    private Pair<TreeNode, Integer> dfs(TreeNode root) {
        if(root == null) {
            return new Pair<>(null, 0);
        }

        Pair<TreeNode, Integer> leftResult = dfs(root.left);
        Pair<TreeNode, Integer> rightResult = dfs(root.right);

        int leftDepth = leftResult.getValue();
        int rightDepth = rightResult.getValue();

        if(leftDepth > rightDepth) {
            return new Pair<>(leftResult.getKey(), leftDepth + 1);
        }

        if(leftDepth < rightDepth) {
            return new Pair<>(rightResult.getKey(), rightDepth + 1);
        }

        return new Pair<>(root, leftDepth + 1);
    }
}