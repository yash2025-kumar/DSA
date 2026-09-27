class Solution {
    public String reverseParentheses(String s) {
        int n = s.length();
        int[] pair = new int[n];
        Stack<Integer> openParenthesesIndices = new Stack<>();

        for(int i=0; i<n; i++) {
            if(s.charAt(i) == '(') {
                openParenthesesIndices.push(i);
            }
            else if(s.charAt(i) == ')') {
                int j = openParenthesesIndices.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        StringBuilder result = new StringBuilder();
        int direction = 1;

        for(int i=0; i<n; i+=direction) {
            char ch = s.charAt(i);
            if(ch == '(' || ch == ')') {
                i = pair[i];
                direction = -direction;
            }
            else {
                result.append(ch);
            }
        }
        return result.toString();
    }
}