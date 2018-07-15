/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    int add1 = 0,add2 = 0,sum = 0;
    struct ListNode* l_sum  = (struct ListNode *)malloc(sizeof(struct ListNode));
    int carry = 0; 
    struct ListNode *p=l_sum;
    p->next = NULL;
    while(l1 != NULL  || l2 != NULL){
        
        add1 = (l1 != NULL)?l1->val:0;
        add2 = (l2 != NULL)?l2->val:0;
        sum = carry + add1 + add2;
        carry = sum/10;
        l_sum -> val = sum % 10;
        if(l1 != NULL && l2 !=NULL){
            if(l1->next != NULL  || l2->next != NULL){
                l_sum->next  = (struct ListNode *)malloc(sizeof(struct ListNode));
                l_sum = l_sum->next;
            }
        }else if(l1 == NULL && l2 !=NULL){
            if(l2->next != NULL){
                l_sum->next  = (struct ListNode *)malloc(sizeof(struct ListNode));
                l_sum = l_sum->next;
            }
        }else if(l1 != NULL && l2 ==NULL){
            if(l1->next != NULL){
                l_sum->next  = (struct ListNode *)malloc(sizeof(struct ListNode));
                l_sum = l_sum->next;
            }
        
        }
        l1 = (l1!=NULL?l1->next:NULL);
        l2 = (l2!=NULL?l2->next:NULL);

    }

    if(carry > 0){
        l_sum->next  = (struct ListNode *)malloc(sizeof(struct ListNode));
        l_sum = l_sum->next;
        l_sum ->val = 1;
    }
    
    l_sum->next = NULL;
    
    
    return p;
    
}
