bool isValid(char* s) {
    

    int n=0,i=0,len = strlen(s);
    char *stack = malloc(sizeof(char)*len);
    
    while(s[i]!='\0'){
        
        switch(s[i]){
            case '(':
            case '[':
            case '{':
                stack[n] = s[i];
                n++;
                break;
            case ')':
                n--;
                if(stack[n] != '(') return false;
                break;
            case ']':
                n--;
                if(stack[n] != '[') return false;
                break;
            case '}':
                n--;
                if(stack[n] != '{') return false;
                break; 
            default:return false;
        }
        
        i++;
    }
    
    
    return n==0;
        
    
}
