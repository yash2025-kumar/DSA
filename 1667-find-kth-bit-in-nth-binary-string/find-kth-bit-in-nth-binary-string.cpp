class Solution {
public:
    char findKthBit(int n, int k) {
        int flipped = 0, len = (1 << n) - 1;

        while(k > 1) {
            if(k == (len >> 1) + 1) {
                flipped ^= 1;
                break;
            }

            if(k > (len >> 1) + 1) {
                k = len - k + 1;
                flipped ^= 1;
            }

            len >>= 1;
        }

        return '0' + flipped;
    }
};