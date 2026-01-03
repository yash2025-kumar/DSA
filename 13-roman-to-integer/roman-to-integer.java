class Solution {
    public int romanToInt(String s) {
        String romanChars = "IVXLCDM";
        int[] romanValues = {1, 5, 10, 50, 100, 500, 1000};

        Map<Character, Integer> romanToValueMap = new HashMap<>();
        for (int i = 0; i < romanValues.length; i++) {
            romanToValueMap.put(romanChars.charAt(i), romanValues[i]);
        }

        int length = s.length();

        int result = romanToValueMap.get(s.charAt(length - 1));

        for (int i = 0; i < length - 1; i++) {
            int sign = romanToValueMap.get(s.charAt(i)) < romanToValueMap.get(s.charAt(i + 1)) ? -1 : 1;
            result += sign * romanToValueMap.get(s.charAt(i));
        }
        return result;
    }
}