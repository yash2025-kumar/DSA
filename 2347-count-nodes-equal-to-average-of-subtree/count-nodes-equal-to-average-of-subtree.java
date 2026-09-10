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
    private int matchingNodesCount = 0;
    
    public int averageOfSubtree(TreeNode root) {
        calculateSumAndCount(root);
        return matchingNodesCount;
    }

    private int[] calculateSumAndCount(TreeNode root) {
        if(root == null) {
            return new int[]{0,0};
        }
        int[] leftSubTree = calculateSumAndCount(root.left);
        int[] rightSubTree = calculateSumAndCount(root.right);

        int totalSum = leftSubTree[0] + rightSubTree[0] + root.val;
        int totalCount = leftSubTree[1] + rightSubTree[1] + 1;

        if(totalSum / totalCount == root.val) {
            matchingNodesCount++;
        }
        return new int[]{totalSum,totalCount};
    }
}