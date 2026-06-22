class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] count = new int[26];

        for(int i=0; i<text.length(); i++) {
            count[text.charAt(i) - 'a']++;
        }

        int minBalloons = count['b' - 'a'];
        minBalloons = Math.min(minBalloons, count['a' - 'a']);
        minBalloons = Math.min(minBalloons, count['l' - 'a'] / 2);
        minBalloons = Math.min(minBalloons, count['o' - 'a'] / 2);
        minBalloons = Math.min(minBalloons, count['n' - 'a']);

        return minBalloons;
    }
}