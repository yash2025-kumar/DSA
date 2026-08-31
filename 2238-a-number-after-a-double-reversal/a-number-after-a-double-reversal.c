bool isSameAfterReversals(int num) {
    int temp = num;
    int rev1 = 0;
    int rev2 = 0;
    while(temp != 0) {
        rev1 *= 10;
        rev1 += (temp % 10);
        temp /= 10;
    }
    while(rev1 != 0) {
        rev2 *= 10;
        rev2 += (rev1 % 10);
        rev1 /= 10;
    }
    return (rev2 == num) ? true : false;
}