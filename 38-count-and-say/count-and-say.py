class Solution:
    def countAndSay(self, n: int) -> str:
        """
       Generate the nth term of the count-and-say sequence:

       The count-and-say sequence describes the previous term by counting consecutive identical digits.
       Example: "1" -> "11" (one 1) -> "21" (two 1s) -> "1211" (one 2, one 1)

       Args:
           n: The term number to generate (1-indexed)

       Returns:
           The nth term of the count-and-say sequence as a string
        """
        current_term = '1' 

        for _ in range(n - 1):
           index = 0
           next_term_parts = []

           while index < len(current_term):
                run_end = index
                while run_end < len(current_term) and current_term[run_end] == current_term[index]:
                    run_end += 1

                count = run_end - index
                digit = current_term[index]

                next_term_parts.append(str(count))
                next_term_parts.append(digit)

                index = run_end

           current_term = ''.join(next_term_parts)

        return current_term