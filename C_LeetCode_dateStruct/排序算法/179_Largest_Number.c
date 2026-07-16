int cmp(const void* a, const void* b) {
    char s1[30], s2[30];
    sprintf(s1, "%d%d", *(int*)a, *(int*)b);
    sprintf(s2, "%d%d", *(int*)b, *(int*)a);
    return strcmp(s2, s1);
}

char* largestNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    if (nums[0] == 0) return "0";

    char* result = malloc(numsSize * 20 + 1);
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        char tmp[20];
        sprintf(tmp, "%d", nums[i]);
        strcat(result, tmp);
    }
    return result;
}