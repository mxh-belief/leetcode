char* convert(char* s, int numRows) {
    
    int len = strlen(s);
    int row = numRows<len?numRows:len;
    char *reslut;

    int i,iv1,iv2;
    bool flag = 0;
  
    
    int x=0;
    
    if(s == NULL){
        return NULL;
    }
    
    if(len <=numRows || numRows == 1){
        return s;
    }
    
    reslut = (char *)malloc(sizeof(char)*(len + 1));
    //memset(reslut,0,sizeof(reslut));
    
    char *p = reslut;

    for(i=0;i<row;i++){
        iv1 = 2*row-2-2*i;
        iv2 = 2*i;
        flag = 0;
        x = i;
        while(x<len){
           *p++ = s[x];
            int delta = 0;
            do {
                delta = flag == 0 ? iv1 : iv2;
                flag = !flag;
            } while (delta == 0);
            x += delta;  
        }
    }
    
   

    reslut[len] = '\0';
    return reslut;
    
    
}
