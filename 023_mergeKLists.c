struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    if(l1 == NULL && l2==NULL){
        return NULL;
    }else if(l1 == NULL){
        return l2;
    }else if(l2 == NULL){
        return l1;
    }
    
    struct ListNode* res = malloc(sizeof(struct ListNode));
    struct ListNode* p = res;
    
   
    while(l1!=NULL || l2!=NULL){
        
        
        if(l2!=NULL && l1!=NULL ){
            if(l1->val < l2->val){
                res->val = l1->val;
                l1 = l1->next;
                // printf("1 %d--",res->val);
                res->next =  malloc(sizeof(struct ListNode));
                res = res->next;                
                
            }else{
                
                res->val = l2->val;
                l2 = l2->next;
                // printf("2 %d--",res->val);
                res->next =  malloc(sizeof(struct ListNode));
                res = res->next;
               
            }
        }else if(l2==NULL && l1!=NULL ){
           
            res->val = l1->val;
            l1 = l1->next;
            // printf("3 %d--",res->val);
            if(l1!=NULL){
                res->next =  malloc(sizeof(struct ListNode));
                res = res->next;
            }else{
                res->next = NULL;
            }
            
        }else if(l2!=NULL && l1==NULL ){

            res->val = l2->val;
            l2 = l2->next;
            // printf("4 %d--",res->val);
            if(l2!=NULL){
                res->next =  malloc(sizeof(struct ListNode));
                res = res->next; 
            }else{
                res->next = NULL;
            }
            
        }
        

    }
    
  
    
    return p;
}


struct ListNode* merge(struct ListNode **lists, int begin ,int end)
{
    if(begin > end) return NULL;
    if(begin == end) return lists[begin];
    
    int mid=(begin+end)/2;
    struct ListNode *left=merge(lists,begin,mid);
    struct ListNode *right=merge(lists,mid+1,end);
    
    return mergeTwoLists(left,right);
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    
//     if(listsSize <=0){
//         return NULL;
//     }else if(listsSize == 1){
//         return lists[0];
//     }
    
//     struct ListNode* add1 = NULL;
//     int i=2;
    
//    for(i=0;i<listsSize;i++){
//         add1 = mergeTwoLists(add1,lists[i]);
//     }
    
//     return add1;
    
    return merge(lists,0,listsSize-1);
    
}
