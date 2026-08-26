int digitMultiplication(int n) {
    int prod = 1;
    while(n != 0) {
        int d = n % 10;
        prod *= d;
        n /= 10;
    }
    return prod;
}
int smallestNumber(int n, int t) {
    while(digitMultiplication(n)%t != 0) n++;
    return n;
}
    
    


    