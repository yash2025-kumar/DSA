class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder result = new StringBuilder();

        boolean[] used = new boolean[n + 1];

        for (int position = 0; position < n; position++) {
            int factorial = 1;
            for (int i = 1; i < n - position; i++) {
                factorial *= i;
            }

            for (int number = 1; number <= n; number++) {
                if(!used[number]) {
                    if (k > factorial) {
                        k -= factorial;
                    }
                    else {
                        result.append(number);
                        used[number] = true;
                        break;
                    }
                }
            }
        }
        return result.toString();
    }
}