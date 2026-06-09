/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int s = 0;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tail = head;
    while (l1 && l2) {
        struct ListNode *newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = (l1->val + l2->val + s) % 10;
        s = (l1->val + l2->val + s) / 10;
        l1 = l1->next;
        l2 = l2->next;
        tail->next = newnode;
        tail = newnode;
    }
    while (l1) {
        struct ListNode *newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = (l1->val + s) % 10;
        s = (l1->val + s) / 10;
        l1 = l1->next;
        tail->next = newnode;
        tail = newnode;
    }
    while (l2) {
        struct ListNode *newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = (l2->val + s) % 10;
        s = (l2->val + s) / 10;
        l2 = l2->next;
        tail->next = newnode;
        tail = newnode;
    }
    if (s) {
        struct ListNode *newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = s;
        tail->next = newnode;
        tail = newnode;
    }
    tail->next = NULL;
    return head->next;
}