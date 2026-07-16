/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode head={0,NULL};//虚拟头节点
    struct ListNode*tail=&head;//记录尾结点
    while(list1&&list2){
        if(list1->val<=list2->val){
            tail->next=list1;//连接尾节点
            list1=list1->next;//list1前移
        }
        else{
            tail->next=list2;
            list2=list2->next;
        }
        tail=tail->next;//尾节点前移
    }
    tail->next=list1?list1:list2;//连接剩下节点
    return head.next;//真正的节点，注意head不是指针
}