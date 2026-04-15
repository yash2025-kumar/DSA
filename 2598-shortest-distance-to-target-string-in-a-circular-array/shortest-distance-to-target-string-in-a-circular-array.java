class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        int n = words.length;
        int minDistance = Integer.MAX_VALUE;

        for(int i = 0; i < n; i++) {
            if(words[i].equals(target)) {
                int d = Math.abs(i - startIndex);
                int currentDistance = Math.min(d, n - d);
                minDistance = Math.min(minDistance, currentDistance);
            }
        }

        return minDistance == Integer.MAX_VALUE ? -1 : minDistance;
    }
}