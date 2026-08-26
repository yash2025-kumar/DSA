bool checkDivisibility(int n) {
    int digitSum = 0;
    int digitProduct = 1;
    int temp = n;
    while(n > 0) {
        int digit = n % 10;
        digitSum += digit;
        digitProduct *= digit;
        n /= 10;
    }

    int sum = digitSum + digitProduct;

    if(temp % sum == 0) {
        return true;
    }
    else {
        return false;
    }
}