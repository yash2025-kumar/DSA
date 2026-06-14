/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int pairSum(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode secondHalfHead = reverseList(slow);

        ListNode firstHalfHead = head;
        int maxTwinSum = 0;

        while(secondHalfHead != null) {
            int currentSum = firstHalfHead.val + secondHalfHead.val;
            maxTwinSum = Math.max(maxTwinSum, currentSum);
            firstHalfHead = firstHalfHead.next;
            secondHalfHead = secondHalfHead.next;
        }

        return maxTwinSum;
    }

        private ListNode reverseList(ListNode head) {
            ListNode prev = null;
            ListNode current = head;

            while(current != null) {
                ListNode nextTemp = current.next;
                current.next = prev;
                prev = current;
                current = nextTemp;
            }
            return prev;
        }
    }
