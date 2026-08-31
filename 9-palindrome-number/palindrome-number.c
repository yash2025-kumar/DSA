bool isPalindrome(int x) {
    int temp = x;
    long rev = 0;
    while(temp != 0) {
        rev *= 10;
        rev += (temp % 10);
        temp /= 10;
    }
    if(x < 0) return false;
    else if(x == rev) return true;
    else return false;
}