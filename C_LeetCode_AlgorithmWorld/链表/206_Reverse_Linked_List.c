/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode*pre=NULL;
    struct ListNode*cur=head;
    while(cur){
        struct ListNode*node=(struct ListNode*)malloc(sizeof(struct ListNode));//创建新节点
        node->val=cur->val;//赋值值
        node->next=pre;//链接上一个节点
        pre=node;//更新头
        cur=cur->next;//原链表向前
    }
    return pre;
}