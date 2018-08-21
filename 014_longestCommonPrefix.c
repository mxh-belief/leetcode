char* longestCommonPrefix(char** strs, int strsSize) {
    
    // if(strsSize == 0){
    //     return NULL;
    // }else if(strsSize == 1){
    //     return strs[0];
    // }
    
    char *common = (char*)malloc(1000);
    int i = 0,j;//flag = 1;
    
    while(strs[0][i] != '\0' ){
        
        // flag = 0;
        
        for(j = 1; j<strsSize;j++){
            
            if(strs[0][i] != strs[j][i]){
                break;
            }
        }
        if(j == strsSize){
            common[i] = strs[0][i];
            i++;
            // flag = 1;
        }else{
            break;
        }
     
    }
    
     common[i++] = '\0';
     return common;
    
    
    
    
}
