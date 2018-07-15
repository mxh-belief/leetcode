int lengthOfLongestSubstring(char* s) {
    
    // char *p = (char *)malloc(sizeof(char));
    char p[128];
    char curr;
    int i=0,max_l = 0, curr_l = 0,last_l = 0, flag = 0 , j=0;
    int rep = 0;
    
    curr = s[0];
    // p[0] = s[0];
    
    while(curr != '\0'){
        

        for(j = 0;j<curr_l;j++){
            if(p[j] == curr){
                rep = j;
                flag = 1; 
            }
        }
        
        if(flag){
           
            max_l = (curr_l > max_l)?curr_l:max_l;
            last_l = curr_l;
            curr_l = last_l - rep ;
            for(j = rep + 1;j < last_l;j++){
                    p[j-rep-1] = p[j];
            }
            p[last_l - rep -1] = curr;
        
             // max_l = (curr_l > last_l) ? curr_l : last_l;
        }else{
            curr_l++;
            p[curr_l - 1] = curr;
            max_l = (curr_l > max_l)?curr_l:max_l;
        }
        
        flag = 0;
        // max_l = curr_l > last_l?curr_l:last_l;
        
        i++;
        curr = s[i];

        
    }
    
    return max_l;
    
}
