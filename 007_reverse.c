int reverse(int x) {
    
    if(x>-10&&x<10){
        return x;
    }
    
    int reverse=0,flag=0,m;
  
    
    if(x<0){
        flag = 1;
        x = -x;
    }
    
    while(x!=0){
        m = x%10;
        if(reverse > (INT_MAX-m)/10) {
            return 0;
        }
        reverse = 10*reverse+m;

        x=x/10;
    }

    if(flag){
        return -1*reverse;
    }else{
        return reverse;
    }
    
}
