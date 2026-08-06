class Solution {
public:
    int smallestNumber(int n, int t) {
        while(!hasDivisibleDigitProduct(n, t)) {
            n++;
        }
        return n;
    }

    private:
        bool hasDivisibleDigitProduct(int num, int t) {
            int digitProduct = 1;

            while(num > 0) {
                digitProduct *= (num % 10);
                num /= 10;
            }

            return (digitProduct % t == 0);
        }
};