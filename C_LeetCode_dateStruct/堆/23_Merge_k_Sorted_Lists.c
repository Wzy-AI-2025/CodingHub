/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void heapadjust(struct ListNode **heap,int n,int i){
    int left=2*i+1;
    int right=2*i+2;
    int min=i;//记录最小值位置
    if(left<n&&heap[left]->val<heap[min]->val)min=left;
    if(right<n&&heap[right]->val<heap[min]->val)min=right;
    if(min!=i){
        struct ListNode*cur=heap[i];
        heap[i]=heap[min];
        heap[min]=cur;
        heapadjust(heap,n,min);
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize==0)return NULL;
    struct ListNode dummy;
    struct ListNode *tail=&dummy;
    int heap_size=0;
    struct ListNode **heap=(struct ListNode**)malloc(sizeof(struct ListNode*)*10001);
    for(int i=0;i<listsSize;i++){
        if(lists[i]!=NULL)heap[heap_size++]=lists[i];
    }//取出非空链表头
    if(heap_size==0)return NULL;
    //从堆底构建小顶堆
    for(int i=(heap_size-1)/2;i>=0;i--){
        heapadjust(heap,heap_size,i);
    }
    while(heap_size>0){
    tail->next=heap[0];//取出表头
    tail=tail->next;
    if(heap[0]->next!=NULL){heap[0]=heap[0]->next;heapadjust(heap,heap_size,0);}
    else {heap[0]=heap[--heap_size];heapadjust(heap,heap_size,0);}
    }
    free(heap);
    return dummy.next;
}