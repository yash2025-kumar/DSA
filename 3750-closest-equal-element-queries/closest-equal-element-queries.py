class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        # Get the length of the input array
        n = len(nums)

        # Double the length to handle circular array logic
        doubled_length = n * 2

        # Initialize minimum distances array with maximum possible value
        min_distances = [doubled_length] * doubled_length

        # First pass: Calculate distances looking from left to right
        # Track the last seen position of each value
        last_position_left = {}
        for i in range(doubled_length):
            # Get current value (using modulo for circular array)
            current_value = nums[i % n]

            # If we've seen this value before, calculate distance
            if current_value in last_position_left:
                min_distances[i] = min(min_distances[i], i - last_position_left[current_value])

            # Update the last seen position for this value
            last_position_left[current_value] = i

        # Second pass: Calculate distances looking from right to left
        # Track the next position of each value when traversing backwards
        next_position_right = {}
        for i in range(doubled_length - 1, -1, -1):
            # Get current value (using modulo for circular array)
            current_value = nums[i % n]

            # If we've seen this value before (while going backwards), calculate distance
            if current_value in next_position_right:
                min_distances[i] = min(min_distances[i], next_position_right[current_value] - i)

            # Update the next position for this value
            next_position_right[current_value] = i

        # Merge distances from both halves of the doubled array
        # This handles the circular nature of the problem
        for i in range(n):
            min_distances[i] = min(min_distances[i], min_distances[i + n])

        # Process queries and return results
        # Return -1 if no valid distance found (distance >= n), otherwise return the distance
        return [-1 if min_distances[query_index] >= n else min_distances[query_index]
                for query_index in queries]
