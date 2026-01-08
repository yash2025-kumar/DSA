/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function maxProduct(root: TreeNode | null): number {
    const calculateTotalSum = (node: TreeNode | null): number => {
        if(!node) {
            return 0;
        }
        return node.val + calculateTotalSum(node.left) + calculateTotalSum(node.right);
    };

    const totalSum: number = calculateTotalSum(root);

    let maxProductValue: number = 0;

    const MODULO: number = 1e9 + 7;

    const findMaxProductDFS = (node: TreeNode | null): number => {
        if (!node) {
            return 0;
        }

        const currentSubtreeSum: number = node.val + findMaxProductDFS(node.left) + findMaxProductDFS(node.right)

        if (currentSubtreeSum < totalSum) {
            const otherSubtreeSum: number = totalSum - currentSubtreeSum;
            const product: number = currentSubtreeSum * otherSubtreeSum;
            maxProductValue = Math.max(maxProductValue, product);
        }

        return currentSubtreeSum; 
    };

    findMaxProductDFS(root);

    return maxProductValue % MODULO;

}