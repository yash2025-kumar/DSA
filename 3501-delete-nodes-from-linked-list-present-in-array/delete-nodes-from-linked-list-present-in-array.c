



#include <stdlib.h>
#include <stdbool.h>

/*
 * Definition for singly-linked list:
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* modifiedList(int* nums, int numsSize,
                              struct ListNode* head) {
    int *present = (int*)calloc(100001, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        present[nums[i]] = 1;
    }

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        if (present[curr->val]) {
            prev->next = curr->next;
            curr = curr->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    free(present);
    return dummy.next;
}

