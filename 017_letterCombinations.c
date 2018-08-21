/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int charnum(char a){
    
    int count = 0;
    switch(a){
        case '2' :
        case '3' :
        case '4' :
        case '5' :
        case '6' :
        case '8' : count = 3; break;
        case '7' :
        case '9' : count = 4; break;
        default  : count = 0; break;
    }
    return count;
}

char** letterCombinations(char* digits, int* returnSize) {
    
    int len = strlen(digits);
    if(len == 0){
        * returnSize = 0;
        return NULL;
    }
    
    
    char *letter_matrix[10];
    letter_matrix[0] = "";
    letter_matrix[1] = " ";
    letter_matrix[2] = "abc";
    letter_matrix[3] = "def";
    letter_matrix[4] = "ghi";
    letter_matrix[5] = "jkl";
    letter_matrix[6] = "mno";
    letter_matrix[7] = "pqrs";
    letter_matrix[8] = "tuv";
    letter_matrix[9] = "wxyz";
    
    int i,count = 1,k = 0,j,m,front,behind,index,num;
    
    for(i = 0 ; i < len;i++){
        count *= charnum(digits[i]);
    }
    
    char **res = (char *)malloc(sizeof(char*) * count);
    
    for(i = 0 ; i < count;i++){
        res[i] = (char *)malloc(sizeof(char) * (len + 1));
        res[i][len] = '\0';
    }
    
    * returnSize = count;
    behind = count;
    front = 1;

    
    for(i = 0 ; i < len;i++){
        
        num = charnum(digits[i]);
        index = digits[i] - '0';
        
        behind /= num;
        
       // int x = front == 1?0:front;
        //int y = behind ==1?0:behind;
        for(m = 0; m < front; m++){
            for(k = 0;k < num;k++){
                for(j=0;j<behind;j++){
                    res[j + m*num*behind+k*behind][i] = letter_matrix[index][k]; 
                    // printf("%c--", res[j + m*num*behind+k*behind][i]);
                }
            }
        }
        
        front *= num;
    }
    
                                      
    return res;

}
