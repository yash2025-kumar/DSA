class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        # Step 1: Calculate the exact number of misplaced '(' and ')' to remove
        left_rem = 0
        right_rem = 0
        
        for char in s:
            if char == '(':
                left_rem += 1
            elif char == ')':
                if left_rem > 0:
                    left_rem -= 1  # Found a matching pair
                else:
                    right_rem += 1 # Unmatched right parenthesis
        
        ans = set()
        n = len(s)
        
        # Step 2: DFS with pruning
        def dfs(index, l_rem, r_rem, l_count, r_count, current_str):
            # Base Case: processed all characters
            if index == n:
                if l_rem == 0 and r_rem == 0:
                    ans.add(current_str)
                return
            
            # Pruning Condition 1: Not enough remaining characters to fulfill removals
            if (n - index) < (l_rem + r_rem):
                return
                
            # Pruning Condition 2: More ')' than '(' makes the current path invalid
            if l_count < r_count:
                return
            
            char = s[index]
            
            # Choice 1: Skip (remove) the current parenthesis if budget allows
            if char == '(' and l_rem > 0:
                dfs(index + 1, l_rem - 1, r_rem, l_count, r_count, current_str)
            elif char == ')' and r_rem > 0:
                dfs(index + 1, l_rem, r_rem - 1, l_count, r_count, current_str)
            
            # Choice 2: Keep the current character
            if char == '(':
                dfs(index + 1, l_rem, r_rem, l_count + 1, r_count, current_str + char)
            elif char == ')':
                dfs(index + 1, l_rem, r_rem, l_count, r_count + 1, current_str + char)
            else:
                # Always keep non-parentheses letters
                dfs(index + 1, l_rem, r_rem, l_count, r_count, current_str + char)

        # Start the recursion
        dfs(0, left_rem, right_rem, 0, 0, "")
        return list(ans)

        