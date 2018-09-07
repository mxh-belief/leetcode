int divide(int dividend, int divisor) {
    
    long long res = 0;
    bool flag;
    if(dividend>0 ^ divisor>0){
        flag = false;
    }else{
        flag = true;
    }
    //printf("%d--%d",dividend,divisor);
    
    long dvd = labs(dividend);
    long dvs = labs(divisor);
    
    //printf("%I64d--%I64d",dvd,dvs);
    while(dvd >= dvs){
        long long temp = dvs;
        long long count = 1;
        while(dvd>= (temp<<1)){
            temp = temp<<1;
            count=count<<1;
        }
        
        res+=count;
        dvd -=temp;
    }
    
    if(!flag){
        return -res;
    }else{
        if(res>=INT_MAX){
            return INT_MAX;
        }else{
            return res;
        }
    }
    
}
