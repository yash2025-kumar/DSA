class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
      n = len(letters)
      left, right = 0, n - 1
      first_true_index = -1

      while left <= right:
          mid = (left + right) // 2

          if letters[mid] > target:
              first_true_index = mid
              right = mid - 1
          else:
             left = mid + 1

      if first_true_index == -1:
          return letters[0]
      return letters[first_true_index]
