struct ListNode* reverseoneGroup(struct ListNode *pre, struct ListNode *next)
{
        struct ListNode *last = pre->next;
        struct ListNode *cur = last->next;
        while(cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;
    
}


struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    
    if(head == NULL || k ==1){
        return head;
    }
    
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* pre = dummy,*cur = head;
    
    int i = 0;
    
    while(cur != NULL){
        i++;
        if(i%k == 0 ){
            pre = reverseoneGroup(pre , cur->next);
            cur = pre->next;
        }else{
            cur = cur->next;
        }
    }
    
    return dummy->next;
    
}
