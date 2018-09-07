int strStr(char* haystack, char* needle) {
    

    
    
    int i = 0, found = 1,length = 0;
    char *s2 = malloc(sizeof(char)*strlen(haystack));
    
    length = strlen(needle);
    
    if(length == 0){
        return 0;
    }else if(haystack == NULL){
        return -1;
    }
  
    
    while(haystack[i+length-1] != '\0'){ 
        
        strncpy(s2,&haystack[i], length);
        s2[length] = '\0';
         // printf("%s--",s2);
        found = strcmp(needle,s2);
        if(found == 0){
            return i;
        }else{
            i++;
        }
    }
    
    return -1;
    
}
