
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

int** spiralMatrix(int m, int n, struct ListNode* head,
                   int* returnSize, int** returnColumnSizes) {
    int **matrix = (int **)malloc(m * sizeof(int *));
    *returnColumnSizes = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;

        for (int j = 0; j < n; j++) {
            matrix[i][j] = -1;
        }
    }

    *returnSize = m;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (head != NULL && top <= bottom && left <= right) {
        // Left to right
        for (int j = left; j <= right && head != NULL; j++) {
            matrix[top][j] = head->val;
            head = head->next;
        }
        top++;

        // Top to bottom
        for (int i = top; i <= bottom && head != NULL; i++) {
            matrix[i][right] = head->val;
            head = head->next;
        }
        right--;

        // Right to left
        for (int j = right; j >= left && head != NULL; j--) {
            matrix[bottom][j] = head->val;
            head = head->next;
        }
        bottom--;

        // Bottom to top
        for (int i = bottom; i >= top && head != NULL; i--) {
            matrix[i][left] = head->val;
            head = head->next;
        }
        left++;
    }

    return matrix;
}
