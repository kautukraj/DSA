struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2);
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int n=listsSize;
    while(n>=2){
        for(int i=0;i<n/2;i++){
            lists[i]=mergeTwoLists(lists[i],lists[n-i-1]);
        }
        if(n%2==0) n=n/2;
        else n=n/2+1;
    }
    return lists[0];
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    
    if(l1==NULL&&l2==NULL) return NULL;
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    struct ListNode *newNode;
    if(l1->val>=l2->val){
        newNode=l2;
        newNode->next=mergeTwoLists(l1, l2->next);
    }else{
        newNode=l1;
        newNode->next=mergeTwoLists(l1->next, l2); 
    }
    return newNode;
}
