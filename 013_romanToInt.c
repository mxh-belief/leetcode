static int convert(char c){

    
    switch(c) {
        case 'I':  
            return 1;  
        case 'V':  
            return 5;  
        case 'X':  
            return 10;  
        case 'L':  
            return 50;  
        case 'C':  
            return 100;  
        case 'D':  
            return 500;  
        case 'M':  
            return 1000;  
        default:
            return 0;
    }
}


int romanToInt(char* s) {
     
    if(s == NULL){
        return 0;
    }
    
    int len = strlen(s);
    if(len == 1){
        return convert(s[0]);
    }
    
    int result = 0;
    int i,pre,curr;
    
    result = convert(s[0]);
    
   for(i = 1;i<len;i++){
       pre  = convert(s[i - 1]);
       curr = convert(s[i]);
       
       if(pre < curr){
          result = result - pre + (curr - pre); 
       }else{
         result = result + curr; 
       }
    
    }
    
    return result;
}
