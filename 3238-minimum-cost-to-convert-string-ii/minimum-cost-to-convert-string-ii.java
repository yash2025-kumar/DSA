class Node {
    Node[] children = new Node[26];  // Array to store child nodes for each letter (a-z)
    int nodeId = -1;  // ID assigned to this node if it represents end of a string
}

class Solution {
    private static final long INFINITY = 1L << 60;  // Large value representing infinity
    private Node trieRoot = new Node();  // Root of the Trie data structure
    private int nodeIdCounter;  // Counter for assigning unique IDs to trie nodes
  
    private long[][] costMatrix;  // Floyd-Warshall shortest path matrix
    private char[] sourceChars;  // Source string as character array
    private char[] targetChars;  // Target string as character array
    private Long[] memoization;  // DP memoization array for minimum cost
  
    public long minimumCost(
        String source, String target, String[] original, String[] changed, int[] cost) {
        int numTransformations = cost.length;
      
        // Initialize cost matrix with maximum possible nodes (2 * number of transformations)
        costMatrix = new long[numTransformations << 1][numTransformations << 1];
        sourceChars = source.toCharArray();
        targetChars = target.toCharArray();
      
        // Initialize cost matrix with infinity, except diagonal (cost to self = 0)
        for (int i = 0; i < costMatrix.length; ++i) {
            Arrays.fill(costMatrix[i], INFINITY);
            costMatrix[i][i] = 0;
        }
      
        // Build trie and populate initial costs for direct transformations
        for (int i = 0; i < numTransformations; ++i) {
            int fromNodeId = insertIntoTrie(original[i]);
            int toNodeId = insertIntoTrie(changed[i]);
            // Keep minimum cost if multiple transformations exist
            costMatrix[fromNodeId][toNodeId] = Math.min(costMatrix[fromNodeId][toNodeId], cost[i]);
        }
      
        // Floyd-Warshall algorithm to find shortest paths between all pairs
        for (int intermediate = 0; intermediate < nodeIdCounter; ++intermediate) {
            for (int from = 0; from < nodeIdCounter; ++from) {
                // Skip if no path through intermediate node
                if (costMatrix[from][intermediate] >= INFINITY) {
                    continue;
                }
                for (int to = 0; to < nodeIdCounter; ++to) {
                    costMatrix[from][to] = Math.min(
                        costMatrix[from][to], 
                        costMatrix[from][intermediate] + costMatrix[intermediate][to]
                    );
                }
            }
        }
      
        // Initialize memoization array and compute result using DFS
        memoization = new Long[sourceChars.length];
        long result = computeMinimumCost(0);
        return result >= INFINITY ? -1 : result;
    }
  
    /**
     * Inserts a word into the trie and returns its node ID
     */
    private int insertIntoTrie(String word) {
        Node currentNode = trieRoot;
      
        // Traverse/create path in trie for the word
        for (char character : word.toCharArray()) {
            int index = character - 'a';
            if (currentNode.children[index] == null) {
                currentNode.children[index] = new Node();
            }
            currentNode = currentNode.children[index];
        }
      
        // Assign unique ID to the end node if not already assigned
        if (currentNode.nodeId < 0) {
            currentNode.nodeId = nodeIdCounter++;
        }
        return currentNode.nodeId;
    }
  
    /**
     * DFS with memoization to find minimum cost to transform source to target
     * starting from position i
     */
    private long computeMinimumCost(int position) {
        // Base case: reached end of string
        if (position >= sourceChars.length) {
            return 0;
        }
      
        // Return memoized result if available
        if (memoization[position] != null) {
            return memoization[position];
        }
      
        // Option 1: If characters match, skip transformation
        long minCost = sourceChars[position] == targetChars[position] ? 
            computeMinimumCost(position + 1) : INFINITY;
      
        // Option 2: Try all possible substring transformations starting at position
        Node sourceNode = trieRoot;
        Node targetNode = trieRoot;
      
        for (int endPos = position; endPos < sourceChars.length; ++endPos) {
            // Traverse both tries simultaneously
            sourceNode = sourceNode.children[sourceChars[endPos] - 'a'];
            targetNode = targetNode.children[targetChars[endPos] - 'a'];
          
            // Stop if either path doesn't exist
            if (sourceNode == null || targetNode == null) {
                break;
            }
          
            // Skip if not complete words in trie
            if (sourceNode.nodeId < 0 || targetNode.nodeId < 0) {
                continue;
            }
          
            // Check if transformation exists and update minimum cost
            long transformationCost = costMatrix[sourceNode.nodeId][targetNode.nodeId];
            if (transformationCost < INFINITY) {
                minCost = Math.min(minCost, transformationCost + computeMinimumCost(endPos + 1));
            }
        }
      
        // Memoize and return result
        memoization[position] = minCost;
        return minCost;
    }
}