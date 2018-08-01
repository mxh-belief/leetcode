int myAtoi(char* str) {
    

    int i= 0;
    int result = 0;
    int flag_min = 0;
    
    if(str == NULL){
        return 0;
    }

    while(str[i] != '\0'){

        //printf("3---%d\n",i);
        if(str[i] == '-'){
            flag_min = 1;
            break;
        }else if(str[i]>='0'&&str[i]<='9'){
            result = str[i] - '0';
            //printf("1---%d\n",result);
            break;
        }else if(str[i] == ' '){
             flag_min = 0;
            // printf("1---%d\n",i);
        }else if(str[i] == '+'){
            flag_min = 0;
            break;
        }else{
            return 0;
        }

        i++;
    }

    i++;

    while(str[i]>='0'&&str[i]<='9'){

        if(flag_min){
            if(result > (INT_MAX )/10 || (result == (INT_MAX )/10 )&& str[i]>='8'){
                return INT_MIN;
            }    
        }else{
            if(result > (INT_MAX )/10 || (result == (INT_MAX )/10 )&& str[i]>='7'){
                return INT_MAX;
            }
        }
        result = result*10 + (str[i] - '0');
        i++;
    }

    return flag_min? -1*result:result;

    
}
