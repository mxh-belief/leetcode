/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    
    if(numsSize < 3){
        *returnSize = 0;
        return NULL;
    }
    
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    
    int i,first,last,sum,count = -1;
    int **result = (int **)malloc(sizeof(int) *(numsSize*(numsSize -1)*(numsSize -2 )/6));
    
    for(i=0;i<numsSize;i++){

        if(i>0 && nums[i] == nums[i - 1]){
            continue;
        }
        first = i+1; last = numsSize -1;
        while(first<last){
            sum = nums[i] + nums[first] + nums[last];
            if(sum == 0){
                count++;
                 result[count] =  (int *)malloc(sizeof(int)*3);
                 result[count][0] =  nums[i];
                 result[count][1] =  nums[first];
                 result[count][2] =  nums[last];
                 first++;
                 last--;
                 while(first<last && nums[first] == nums[first-1]) first++;
                 while(first<last && nums[last] == nums[last+1])   last--; 
            }else if(sum < 0){
                first++;
            }else{
                last--;
            }
        }
    }
    
    *returnSize = count + 1;
    return result;
    
}
