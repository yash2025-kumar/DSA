class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int length = s.size();

         while (index < length && s[index] == ' ') {
            ++index;
        }

        int sign = 1;
        if (index < length && (s[index] == '-' || s[index] == '+')) {
            sign = (s[index] == '-') ? -1 : 1;
            ++index;
        }
        int result = 0;
        while (index < length && isdigit(s[index])) {
            int digit = s[index] - '0';

            if (result > INT_MAX / 10 || 
                (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                    return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            ++index;
        }
            return result * sign;
    }
};