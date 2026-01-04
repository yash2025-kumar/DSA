class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        """
        Find the first occurrence of needle in haystack.

        Args:
            haystack: The string to search in
            needle: The substring to search for

        Returns:
            The index of the first occurrence of needle in haystack,
            or -1 if needle is not found
        """

        haystack_length = len(haystack)
        needle_length = len(needle)

        for start_index in range(haystack_length - needle_length + 1):
            if haystack[start_index:start_index + needle_length] == needle:
                return start_index

        return -1
