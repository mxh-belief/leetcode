static char Roman[64];

char* intToRoman(int num) {
    
    if(num == 0){
        return NULL;
    }
    //char Roman[16];
    char *r = &Roman[0];
    
    memset(Roman, 0, sizeof(Roman));
    
    int digits[4], i= 0 ;
    
    for(i=0;i<4;i++){
        digits[i] = num%10;//digits[0] 个位
        num = num/10;
        //printf("%d--",digits[i]);
    }
    
    if (digits[3] > 0) {
        if (digits[3] < 4) {
            for (i = 0; i < digits[3]; i++) {
                *r++ = 'M';
            }
        }
    }

    digitTochar(digits[2],&r,2);
    digitTochar(digits[1],&r,1);
    digitTochar(digits[0],&r,0);
 
    return Roman;
    
}

void digitTochar(int num, char **s, int pattern){
    
    char high,mid,low;
    int i;
    char *str = *s;
    
    switch(pattern){
        case 0:
            high = 'X';
            mid  = 'V';
            low  = 'I';
            break;
        case 1:
            high = 'C';
            mid  = 'L';
            low  = 'X';
            break;
        case 2:
            high = 'M';
            mid  = 'D';
            low  = 'C';
            break;
    }
    
    if(num>0){
        switch(num){
            case 1: 
            case 2:
            case 3 :
                for (i = 0; i < num; i++) {
                    *str++ = low;
                }
                break;
            case 4: 
                *str++ = low;
                *str++ = mid;
                break;
            case 5:
                *str++ = mid;
                break;
            case 6:
            case 7: 
            case 8:
                *str++ = mid;
                for (i = 5; i < num; i++) {
                    *str++ = low;
                }
                break;
            case 9 :
                *str++ = low;
                *str++ = high;
                break;          
            
        }   
    }

     *s = str;
    

}
