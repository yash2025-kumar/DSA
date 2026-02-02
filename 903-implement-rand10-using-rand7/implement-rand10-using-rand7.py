# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        while True:
            row = rand7() - 1
            
            col = rand7()

            combined_value = row * 7 + col

            if combined_value <= 40:
                return combined_value % 10 + 1