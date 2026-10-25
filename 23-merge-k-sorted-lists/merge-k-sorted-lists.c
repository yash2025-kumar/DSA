#include <stddef.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Helper function to merge two sorted linked lists in-place
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Append the remaining nodes of whichever list is not empty
    tail->next = l1 ? l1 : l2;

    return dummy.next;
}

// Helper function to handle the divide and conquer logic
struct ListNode* divideAndConquer(struct ListNode** lists, int start, int end) {
    if (start > end) return NULL;
    if (start == end) return lists[start];
    
    int mid = start + (end - start) / 2;
    
    // Divide into two halves
    struct ListNode* left = divideAndConquer(lists, start, mid);
    struct ListNode* right = divideAndConquer(lists, mid + 1, end);
    
    // Conquer by merging the sorted halves
    return mergeTwoLists(left, right);
}

// Main entry point for LeetCode
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0 || lists == NULL) return NULL;
    return divideAndConquer(lists, 0, listsSize - 1);
}
