/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode*cur=head;
    struct ListNode*pre=NULL;
    while(cur){
    struct ListNode*next=cur->next;//记录下一个节点
    cur->next=pre;//调转指针方向
    pre=cur;//记录表头
    cur=next;//下一个
    }
    return pre;
}