/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    int turn=0;
    struct ListNode*fast=head;
    struct ListNode*slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){//说明有环
        slow=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
        }
    }
    return 0;
}