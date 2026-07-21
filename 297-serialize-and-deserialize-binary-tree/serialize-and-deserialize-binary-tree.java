/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    /**
     * Serializes a binary tree to a string representation using level-order traversal.
     * Uses BFS to traverse the tree and represents null nodes with "#".
     * 
     * @param root The root node of the binary tree to serialize
     * @return A comma-separated string representation of the tree, or null if tree is empty
     */
    public String serialize(TreeNode root) {
        // Handle empty tree case
        if (root == null) {
            return null;
        }
      
        // List to store the serialized node values
        List<String> serializedNodes = new ArrayList<>();
      
        // Queue for BFS traversal
        Deque<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
      
        // Perform level-order traversal
        while (!queue.isEmpty()) {
            TreeNode currentNode = queue.poll();
          
            if (currentNode != null) {
                // Add node value to result and enqueue children
                serializedNodes.add(String.valueOf(currentNode.val));
                queue.offer(currentNode.left);
                queue.offer(currentNode.right);
            } else {
                // Use "#" to represent null nodes
                serializedNodes.add("#");
            }
        }
      
        // Join all values with comma separator
        return String.join(",", serializedNodes);
    }

    /**
     * Deserializes a string representation back into a binary tree.
     * Reconstructs the tree using BFS, processing nodes in the same order they were serialized.
     * 
     * @param data The comma-separated string representation of the tree
     * @return The root node of the reconstructed binary tree, or null if data is null
     */
    public TreeNode deserialize(String data) {
        // Handle empty tree case
        if (data == null) {
            return null;
        }
      
        // Split the serialized string into individual node values
        String[] nodeValues = data.split(",");
        int index = 0;
      
        // Create root node from first value
        TreeNode root = new TreeNode(Integer.valueOf(nodeValues[index++]));
      
        // Queue to maintain nodes whose children need to be processed
        Deque<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
      
        // Process nodes level by level
        while (!queue.isEmpty()) {
            TreeNode currentNode = queue.poll();
          
            // Process left child
            if (!"#".equals(nodeValues[index])) {
                currentNode.left = new TreeNode(Integer.valueOf(nodeValues[index]));
                queue.offer(currentNode.left);
            }
            index++;
          
            // Process right child
            if (!"#".equals(nodeValues[index])) {
                currentNode.right = new TreeNode(Integer.valueOf(nodeValues[index]));
                queue.offer(currentNode.right);
            }
            index++;
        }
      
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));