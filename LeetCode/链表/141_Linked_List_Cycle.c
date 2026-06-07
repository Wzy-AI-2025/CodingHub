/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode*fast=head;
    struct ListNode*slow=head;
    while(fast!=NULL){
        for(int i=0;i<2;i++){
            fast=fast->next;
            if(fast==NULL)return 0;
        }
        slow=slow->next;
        if(fast==slow){
            return 1;
        }
    }
    return 0;
}