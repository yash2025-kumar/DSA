class Solution {
    private List<Integer>[] tree;
    private int[] ans;
    private int[] lastSeen;
    private String s;

    public int[] findSubtreeSizes(int[] parent, String s) {
        int n = parent.length;
        this.s = s;
        this.ans = new int[n];
        this.lastSeen = new int[26];
        Arrays.fill(lastSeen, -1);

        tree = new ArrayList[n];
        for(int i=0; i<n; i++) {
            tree[i] = new ArrayList<>();
        }
        for(int i=1; i<n; i++) {
            tree[parent[i]].add(i);
        }

        dfs(0, -1);
        return ans;
    }

    private void dfs(int curr, int origParent) {
        int charIdx = s.charAt(curr) - 'a';
        int prevAncestor = lastSeen[charIdx];

        int targetParent = (prevAncestor != -1) ? prevAncestor : origParent;

        lastSeen[charIdx] = curr;
        ans[curr] = 1;

        for(int child : tree[curr]) {
            dfs(child, curr);
        } 

        lastSeen[charIdx] = prevAncestor;

        if(targetParent != -1) {
            ans[targetParent] += ans[curr];
        }
    }
}