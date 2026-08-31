# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        # We need at least 3 nodes to have a critical point
        if not head or not head.next or not head.next.next:
            return [-1, -1]
        
        min_dist = float('inf')
        
        first_critical_index = -1
        prev_critical_index = -1
        
        # Pointers to evaluate local minima/maxima
        prev = head
        curr = head.next
        index = 1  # 0-indexed position tracker for 'curr'
        
        while curr.next:
            # Check if curr is a local maxima or local minima
            is_maxima = curr.val > prev.val and curr.val > curr.next.val
            is_minima = curr.val < prev.val and curr.val < curr.next.val
            
            if is_maxima or is_minima:
                if first_critical_index == -1:
                    # Mark the very first critical point found
                    first_critical_index = index
                else:
                    # Update the minimum distance between adjacent critical points
                    min_dist = min(min_dist, index - prev_critical_index)
                
                # Update the previous critical point index to the current one
                prev_critical_index = index
                
            # Move pointers forward
            prev = curr
            curr = curr.next
            index += 1
            
        # If fewer than two critical points were found
        if min_dist == float('inf'):
            return [-1, -1]
            
        # Max distance is the gap between the last and first critical points
        max_dist = prev_critical_index - first_critical_index
        
        return [min_dist, max_dist]

        