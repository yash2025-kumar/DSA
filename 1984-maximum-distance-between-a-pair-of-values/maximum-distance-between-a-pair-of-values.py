class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        max_distance = 0
        n2 = len(nums2)

        for i, value in enumerate(nums1):
            left, right = i, n2 - 1
            first_true_index = -1

            while left <= right:
                mid = (left + right) // 2
                if nums2[mid] < value:
                    first_true_index = mid
                    right = mid - 1
                else:
                    left = mid + 1

            if first_true_index == -1:
                last_valid_j = n2 - 1
            else:
                last_valid_j = first_true_index - 1

            if last_valid_j >= i:
                max_distance = max(max_distance, last_valid_j - i)

        return max_distance