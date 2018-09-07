int removeDuplicates(int* nums, int numsSize) {
    
    int i,result =  numsSize;
    
    for(i=1;i<numsSize;i++){
        if(nums[i] == nums[i-1]){
            result--;
        }
    }
    
    for(i=0;i<result;i++){
        if(nums[i] == nums[i-1]){
            nums[i] = nums;
        }
    }
    
    return result;
    
}
