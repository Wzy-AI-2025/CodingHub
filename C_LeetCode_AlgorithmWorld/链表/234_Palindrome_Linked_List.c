/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode*fast=head;
    struct ListNode*slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    struct ListNode*newhead=NULL;
    while(slow!=NULL){
        struct ListNode*next=slow->next;
        slow->next=newhead;
        newhead=slow;
        slow=next;
    }
    while(newhead!=NULL){
        if(newhead->val!=head->val)return 0;
        newhead=newhead->next;
        head=head->next;
    }
    return 1;
}