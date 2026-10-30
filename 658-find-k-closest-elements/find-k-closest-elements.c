
/**
 * Note: The returned array must be malloced.
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int low = 0;
    int high = arrSize - k;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (x - arr[mid] > arr[mid + k] - x) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }

    int* result = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        result[i] = arr[low + i];
    }

    *returnSize = k;

    return result;
}
