import java.util.*;

class Solution {
    class Item implements Comparable<Item> {
        int l, r, weight, id;
        Item(int l, int r, int weight, int id) {
            this.l = l;
            this.r = r;
            this.weight = weight;
            this.id = id;
        }
        public int compareTo(Item other) {
            if (this.l != other.l) return Integer.compare(this.l, other.l);
            if (this.r != other.r) return Integer.compare(this.r, other.r);
            return Integer.compare(this.weight, other.weight);
        }
    }

    class Result {
        long weight;
        int[] indices;
        Result(long weight, int[] indices) {
            this.weight = weight;
            this.indices = indices;
        }
    }

    private Result[][] memo;
    private List<Item> items;

    public int[] maximumWeight(List<List<Integer>> intervals) {
        int n = intervals.size();
        items = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            items.add(new Item(intervals.get(i).get(0), intervals.get(i).get(1), intervals.get(i).get(2), i));
        }
        
        Collections.sort(items);
        memo = new Result[n + 1][5];

        Result res = dp(0, 4);
        int[] ans = res.indices;
        Arrays.sort(ans);
        return ans;
    }

    private Result dp(int idx, int count) {
        if (count == 0 || idx >= items.size()) {
            return new Result(0, new int[0]);
        }
        if (memo[idx][count] != null) {
            return memo[idx][count];
        }

        
        Result skip = dp(idx + 1, count);

        
        int nextIdx = binarySearch(items.get(idx).r);
        Result takeNext = dp(nextIdx, count - 1);
        
        long takeWeight = (long) items.get(idx).weight + takeNext.weight;
        int[] takeIndices = new int[1 + takeNext.indices.length];
        takeIndices[0] = items.get(idx).id;
        System.arraycopy(takeNext.indices, 0, takeIndices, 1, takeNext.indices.length);
        
        Result take = new Result(takeWeight, takeIndices);

        
        Result best;
        if (take.weight > skip.weight) {
            best = take;
        } else if (take.weight < skip.weight) {
            best = skip;
        } else {
            if (isLexicographicallySmaller(take.indices, skip.indices)) {
                best = take;
            } else {
                best = skip;
            }
        }

        return memo[idx][count] = best;
    }

    private int binarySearch(int endVal) {
        int low = 0, high = items.size(), res = items.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (items.get(mid).l > endVal) {
                res = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }

    private boolean isLexicographicallySmaller(int[] a, int[] b) {
        int[] sortedA = a.clone();
        int[] sortedB = b.clone();
        Arrays.sort(sortedA);
        Arrays.sort(sortedB);
        for (int i = 0; i < Math.min(sortedA.length, sortedB.length); i++) {
            if (sortedA[i] != sortedB[i]) {
                return sortedA[i] < sortedB[i];
            }
        }
        return sortedA.length < sortedB.length;
    }
}
