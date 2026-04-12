/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* previousNode = nullptr;
        TreeNode* firstMisplacedNode = nullptr;
        TreeNode* secondMisplacedNode = nullptr;

        function<void(TreeNode*)> inorderTraversal = [&](TreeNode* currentNode) {
            if(!currentNode) {
                return;
            }

            inorderTraversal(currentNode->left);

            if(previousNode && previousNode->val > currentNode->val) {
                if(!firstMisplacedNode) {
                    firstMisplacedNode = previousNode;
                }

                secondMisplacedNode = currentNode;
            }

            previousNode = currentNode;

            inorderTraversal(currentNode->right);
        };

        inorderTraversal(root);

        swap(firstMisplacedNode->val, secondMisplacedNode->val);
    }
};