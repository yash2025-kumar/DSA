int totalSteps(int* nums, int numsSize) {
    int* value = malloc(numsSize * sizeof(int));
    int* steps = malloc(numsSize * sizeof(int));
    int top = 0, answer = 0;
    for(int i=numsSize-1; i>=0; i--) {
        int mine = 0;
        while(top > 0 && nums[i] > value[top-1]) {
            top--;
            mine = mine + 1 > steps[top] ? mine + 1 : steps[top];
        }
        value[top] = nums[i];
        steps[top] = mine;
        top++;
        if(mine > answer) answer = mine;
    }
    free(value);
    free(steps);
    return answer;
}