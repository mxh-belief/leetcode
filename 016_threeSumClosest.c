// int absx(int a ,int b){
    
//     int diff =a-b;
    
//     return diff>0?diff:-1*diff;
// }

// int threeSumClosest(int* nums, int numsSize, int target) {
    
//     int result = 0,i;
    
//     if(numsSize <= 3){
//         for(i=0;i<numsSize;i++){
//             result +=nums[i];
//         }
        
//         return result;
//     }
    
//     int diff_abs = 0,diff_abs_min = 1000,sum = 0;
//     int j,k;
    
//     for(i=0;i<numsSize;i++){
//        for(j=i+1;j<numsSize;j++){
//            for(k=j+1;k<numsSize;k++){
//                sum = nums[i]+nums[j]+nums[k];
//                diff_abs = absx(sum,target);
//                //printf("%d---",diff_abs);
//                result = diff_abs<diff_abs_min?sum:result;
//                //printf("%d--",result);
//                diff_abs_min = diff_abs<diff_abs_min?diff_abs:diff_abs_min;
//            }
//        } 
//     }
    
//     return result;
    
    
// }


static int compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

static int threeSumClosest(int* nums, int numsSize, int target)
{
    int i, min_diff = INT_MAX;

    if (numsSize < 3) {
        return min_diff;
    }

    qsort(nums, numsSize, sizeof(*nums), compare);

    for (i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int diff = nums[i] + nums[left] + nums[right] - target;
            if (abs(diff) < abs(min_diff)) {
                min_diff = diff;
            }
            if (diff < 0) {
                left++;
            } else if (diff > 0) {
                right--;
            } else {
                return target;
            }
        }
    }
    return min_diff + target;
}
