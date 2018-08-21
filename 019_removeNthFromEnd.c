/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    if(head = NULL){
        return NULL;
    }
    
    int i,count = 0;
    struct ListNode* dummy;
    dummy->next = head;
    struct ListNode*  first = head;
    //first = head;
    
    while(first != NULL){
        count++;
        first = first->next;
         printf("%d--",count);
    }
    
    printf("%d--",count);
    if(n>count){
        return NULL;
    }else if(count == n){
        return dummy->next->next;
    }
    
    first = head;
    for(i=0;i<count-n-1;i++){
        first = first->next;
    }
    
    first->next = first->next->next;
    
    return dummy->next;
    
    
    
}
