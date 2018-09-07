struct ListNode* swapPairs(struct ListNode* head) {
    
    struct ListNode *p =head,*s;
    
    if(p!=NULL && p->next !=NULL){
        s = p->next;
        p->next = s->next;
        s->next = p;
        head = s;
    
    while(p->next!=NULL && p->next->next !=NULL){
        s = p->next->next;
        p->next->next = s->next;
        s->next = p->next;
        p->next = s;
        p = s->next;
        
    }
    
    }
    return head;
    
}
