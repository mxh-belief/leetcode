char* longestPalindrome(char* s) {
    
    int j = 1,i = 0,max_len = 1,len = 1,found = 0,m,x=0;
    char *Palindrome = malloc(sizeof(char)*2000);
    memset(Palindrome,0,sizeof(Palindrome));
    
     if (s == NULL) {
        return NULL;
    }

    int s_len = strlen(s);
    if (s_len <= 1) {
        return s;
    }
    
    for(i=0;i<s_len-1;i++){
        
        if(s[i] == s[i+1]){
            len ++;
            for(j=i+2;j<s_len;j++){
                if(s[i] == s[j]){
                    len++;
                    x++;
                }else{break;}
                
            }
            j = 1;
            while((i - j)>=0 && s[i+1+x+j] !='\0'){
                if(s[i-j] ==  s[i+1+x+j]){
                    len = len + 2;
                    found = j;
                }else{break;}
                j++;
            }
            // if(len >= max_len){
            //     //memset(Palindrome,0,sizeof(Palindrome));
            //     for(m=0;m<len;m++){
            //         Palindrome[m] = s[i-found+m];
            //     }
            // }
        }else{
            j = 1;
            while((i - j)>=0 && s[i+j] !='\0'){
                if(s[i-j] == s[i+j]){
                    len = len +2;
                    found = j;
                }else{break;}
                j++;
            }
           // if(len >= max_len){
           //      //memset(Palindrome,0,sizeof(Palindrome));
           //      for(m=0;m<len;m++){
           //           Palindrome[m] = s[i-found+m];
           //      }  
           // }
            
        }
       
      if(len >= max_len){
            memset(Palindrome,0,sizeof(char)*2000);
            for(m=0;m<len;m++){
              Palindrome[m] = s[i-found+m];
            }  
       }
        
        j= 1;
        found=0;
        max_len = max_len>len?max_len:len;
        len = 1;
        x=0;
        
         
        
    }
    
    


    return Palindrome;
    
}
