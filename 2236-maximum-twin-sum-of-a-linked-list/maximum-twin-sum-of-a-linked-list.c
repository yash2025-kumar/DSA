/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while(curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

int pairSum(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* secondHalfHead = reverseList(slow);
    struct ListNode* firstHalf = head;
    struct ListNode* secondHalf = secondHalfHead;
    int maxSum = 0;

    while(secondHalf != NULL) {
        int currentSum = firstHalf->val + secondHalf->val;
        if(currentSum > maxSum) {
            maxSum = currentSum;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return maxSum;
}