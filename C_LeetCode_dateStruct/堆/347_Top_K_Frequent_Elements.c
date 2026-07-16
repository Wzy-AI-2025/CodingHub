

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

typedef struct {
    int val;
    int count;
} point;

void heapadjust(point *heap, int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min = i;
    if (left < n && heap[left].count < heap[min].count) min = left;
    if (right < n && heap[right].count < heap[min].count) min = right;
    if (min != i) {
        point cur = heap[i];
        heap[i] = heap[min];
        heap[min] = cur;
        heapadjust(heap, n, min);
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    
    // 统计所有数字频率
    point *freq = (point*)malloc(numsSize * sizeof(point));
    int fcount = 0;
    
    for (int i = 0; i < numsSize; ) {
        int j = i;
        while (j < numsSize && nums[j] == nums[i]) j++;
        freq[fcount].val = nums[i];
        freq[fcount].count = j - i;
        fcount++;
        i = j;
    }
    
    // 如果不同数字少于k个
    if (fcount < k) k = fcount;
    
    // 维护大小为k的最小堆
    point *heap = (point*)malloc(k * sizeof(point));
    for (int i = 0; i < k; i++) {
        heap[i] = freq[i];
    }
    
    // 建堆
    for (int i = (k - 1) / 2; i >= 0; i--) {
        heapadjust(heap, k, i);
    }
    
    // 处理剩余元素
    for (int i = k; i < fcount; i++) {
        if (freq[i].count > heap[0].count) {
            heap[0] = freq[i];
            heapadjust(heap, k, 0);
        }
    }
    
    int *result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = heap[i].val;
    }
    
    *returnSize = k;
    free(freq);
    free(heap);
    return result;
}