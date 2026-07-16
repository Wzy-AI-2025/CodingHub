/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head) return NULL;
    
    // 1. 统计链表长度
    int n = 0;
    struct ListNode* cur = head;
    while (cur) { n++; cur = cur->next; }
    
    // 2. 复制值到数组
    int* arr = (int*)malloc(n * sizeof(int));
    cur = head;
    for (int i = 0; i < n; i++) {
        arr[i] = cur->val;
        cur = cur->next;
    }
    
    // 3. 排序
    qsort(arr, n, sizeof(int), cmp);
    
    // 4. 写回链表
    cur = head;
    for (int i = 0; i < n; i++) {
        cur->val = arr[i];
        cur = cur->next;
    }
    free(arr);
    return head;
}