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
    public int sumRootToLeaf(TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode root, int currentSum) {
        if(root == null) {
            return 0;
        }

        currentSum = (currentSum << 1) | root.val;

        if(root.left == null && root.right == null) {
            return currentSum;
        }

        return dfs(root.left, currentSum) + dfs(root.right, currentSum);
    }
}