int longestValidParentheses(char* s) {
    
    
    int n=0,i=0,j=0,len = strlen(s);
    int count = 0,res = 0;
    char *stack = malloc(sizeof(char)*len);
    
     for(i=0;i<len;i++){
         for(j=i;j<len;j++){
             
             if(s[j] == '('){
                stack[n] = s[j];
                n++;                 
             }else{
                n--;
                if(stack[n] != '('){
                    memset(stack,0,sizeof(char)*len);
                    //res = res>count?res:count;
                    count = 0;
                    n=0;                        
                    break;
                }else{
                    count+=2;
                    printf("%d %d--",i,j);
                }
             }
             
             if(n==0){
                res = res>count?res:count;
                memset(stack,0,sizeof(char)*len);
                n=0;
             }
         
       }
    }
    
    return res;
    
}
