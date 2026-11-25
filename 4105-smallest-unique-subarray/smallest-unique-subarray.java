
import java.util.*;

class Solution {
    public int smallestUniqueSubarray(int[] nums) {
        int n = nums.length;

        if (n == 1) return 1;

        // Build suffix array
        Integer[] sa = new Integer[n];
        int[] rank = new int[n];

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }

        for (int k = 1; k < n; k *= 2) {
            final int len = k;
            final int[] r = rank;

            Arrays.sort(sa, (a, b) -> {
                if (r[a] != r[b])
                    return Integer.compare(r[a], r[b]);

                int ra = a + len < n ? r[a + len] : -1;
                int rb = b + len < n ? r[b + len] : -1;

                return Integer.compare(ra, rb);
            });

            int[] newRank = new int[n];
            newRank[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                boolean different =
                    rank[a] != rank[b] ||
                    (a + len < n ? rank[a + len] : -1) !=
                    (b + len < n ? rank[b + len] : -1);

                newRank[b] = newRank[a] + (different ? 1 : 0);
            }

            rank = newRank;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Calculate LCP using Kasai's algorithm
        int[] pos = new int[n];

        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        int[] lcp = new int[n];
        int h = 0;

        for (int i = 0; i < n; i++) {
            int p = pos[i];

            if (p == 0) continue;

            int j = sa[p - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[p] = h;

            if (h > 0) h--;
        }

        // Find minimum unique subarray length
        int ans = n;

        for (int i = 0; i < n; i++) {
            int index = sa[i];

            int maxLcp = lcp[i];

            if (i + 1 < n) {
                maxLcp = Math.max(maxLcp, lcp[i + 1]);
            }

            int required = maxLcp + 1;
            int remaining = n - index;

            if (required <= remaining) {
                ans = Math.min(ans, required);
            }
        }

        return ans;
    }
}
