class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        final int INFINITY = 1 << 29;

        int[][] graph = new int[26][26];

        for(int i = 0; i < 26; i++) {
            Arrays.fill(graph[i], INFINITY);
            graph[i][i] = 0;
        }

        for(int i = 0; i < original.length; i++) {
            int fromChar = original[i] - 'a';
            int toChar = changed[i] - 'a';
            int transformCost = cost[i];
            graph[fromChar][toChar] = Math.min(graph[fromChar][toChar], transformCost);
        }

        for(int intermediate = 0; intermediate < 26; intermediate++) {
            for(int start = 0; start < 26; start++) {
                for(int end = 0; end < 26; end++) {
                    graph[start][end] = Math.min(graph[start][end],
                                                graph[start][intermediate] + graph[intermediate][end]);
                }
            }
        }

        long totalCost = 0;
        int stringLength = source.length();

        for(int i = 0; i < stringLength; i++) {
            int sourceChar = source.charAt(i) - 'a';
            int targetChar = target.charAt(i) - 'a';

            if(sourceChar != targetChar) {
                if (graph[sourceChar][targetChar] >= INFINITY) {
                    return -1;
                }
                totalCost += graph[sourceChar][targetChar];
            }
        }
        return totalCost;
    }
}