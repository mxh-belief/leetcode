/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {

    
    if(numsSize < 4){
        *returnSize = 0;
        return NULL;
    }
    
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    
    int i,j,first,last,sum,count = -1;
    int **result = (int **)malloc(sizeof(int) *(numsSize*(numsSize -1)*(numsSize -2 )*(numsSize -3)/24));   
    
    for(j = 0; j<numsSize;j++ ){
        
        if(j>0 && nums[j] == nums[j - 1]){
            continue;
        }        
        
        for(i=j+1;i<numsSize;i++){
            if(i>j+1 && nums[i] == nums[i - 1]){
                continue;
            }
            first = i+1; last = numsSize -1;
            while(first<last){
                sum = nums[j] + nums[i] + nums[first] + nums[last];
                if(sum == target){
                    count++;
                    result[count] =  (int *)malloc(sizeof(int)*4);
                    result[count][0] =  nums[j];
                    result[count][1] =  nums[i];
                    result[count][2] =  nums[first];
                    result[count][3] =  nums[last];
                    first++;
                    last--;
                    while(first<last && nums[first] == nums[first-1]) first++;
                    while(first<last && nums[last] == nums[last+1])   last--; 
                }else if(sum < target){
                    first++;
                }else{
                    last--;
                }
            }
        }
    }
    
    
    *returnSize = count + 1;
    return result;
    
    
}
