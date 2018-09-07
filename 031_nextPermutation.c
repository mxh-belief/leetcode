int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void nextPermutation(int* nums, int numsSize) {
    
   
    
    int i = 0,j =0 ,temp;
    
    for(i=numsSize-2;i>=0;i--){
        if(nums[i+1]>nums[i]){
            //flag = 1;
            break;
        }
    }
    
    if(i>=0){
    for(j=numsSize-1;j>i;j--){
        if(nums[j] > nums[i]){
            break;
        }
    }
    
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    
    }
    qsort(&nums[i+1],numsSize-i-1,sizeof(int),cmpfunc);
    
}
