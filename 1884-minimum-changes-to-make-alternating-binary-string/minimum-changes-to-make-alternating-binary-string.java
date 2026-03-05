class Solution {
    public int minOperations(String s) {
        int operationsForPattern0 = 0;
        int stringLength = s.length();

        for(int i = 0; i < stringLength; i++) {
            char expectedChar = "01".charAt(i & 1);

            if(s.charAt(i) != expectedChar) {
                operationsForPattern0++;
            }
        }

        return Math.min(operationsForPattern0, stringLength - operationsForPattern0);
    }
}