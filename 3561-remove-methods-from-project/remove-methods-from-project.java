class Solution {
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<n; i++) {
            adj.add(new ArrayList<>());
        }
        for(int[] inv : invocations) {
            adj.get(inv[0]).add(inv[1]);
        }

        boolean[] isSuspicious = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();

        queue.offer(k);
        isSuspicious[k] = true;

        while(!queue.isEmpty()) {
            int current = queue.poll();
            for(int neighbor : adj.get(current)) {
                if(!isSuspicious[neighbor]) {
                    isSuspicious[neighbor] = true;
                    queue.offer(neighbor);
                }
            }
        }

        for(int[] inv : invocations) {
            int source = inv[0];
            int dest = inv[1];

            if(!isSuspicious[source] && isSuspicious[dest]) {
                List<Integer> allMethods = new ArrayList<>();
                for(int i=0; i<n; i++) {
                    allMethods.add(i);
                }
                return allMethods;
            }
        }

        List<Integer> remaining = new ArrayList<>();
        for(int i=0; i<n; i++) {
            if(!isSuspicious[i]) {
                remaining.add(i);
            }
        }
        return remaining;
    }
}