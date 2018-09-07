int removeElement(int* nums, int numsSize, int val) {
    
    int i,count = 0;
    int *res = nums;
    
    for(i = 0;i<numsSize;i++){
        if(nums[i] != val){
            res[count] = nums[i];
            count++;
        }
    }
    
    return count;
    
}
