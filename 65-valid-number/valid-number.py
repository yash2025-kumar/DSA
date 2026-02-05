class Solution:
    def isNumber(self, s: str) -> bool:
     n = len(s)
     index = 0

     if s[index] in '+-':
        index += 1

     if index == n:
        return False

     if s[index] == '.' and (index + 1 == n or s[index + 1] in 'eE'):
        return False

     has_decimal = 0
     has_exponent = 0
     current_index = index

     while current_index < n:
        if s[current_index] == '.':
            if has_exponent or has_decimal:
                return False
            has_decimal += 1

        elif s[current_index] in 'eE':
            if has_exponent or current_index == index or current_index == n - 1:
                return False
            has_exponent += 1

            if s[current_index + 1] in '+-':
                current_index += 1
                if current_index == n - 1:
                    return False

        elif not s[current_index].isnumeric():
            return False

        current_index += 1

     return True   