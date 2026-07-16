/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next=head;
    struct ListNode*fast=&dummy;
    struct ListNode*slow=&dummy;
    for(int i=0;i<n+1;i++){
        fast=fast->next;
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    struct ListNode*cur=slow->next;
    slow->next=slow->next->next;
    free(cur);
    return dummy.next;
}