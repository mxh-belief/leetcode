double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int half_len;
    
    int i,flag,found = 0 ,sort = 0;
    int min_len = nums1Size<=nums2Size?nums1Size:nums2Size;
    int *a= nums1Size<=nums2Size?nums1:nums2;
    int *b= nums1Size>nums2Size?nums1:nums2;
    double mid_value;
    
    if((nums1Size + nums2Size)%2 ==0){
      half_len = (nums1Size + nums2Size)/2;  
      flag = 0;
    }else{
      half_len = (nums1Size + nums2Size)/2;  
      flag = 1;
    }
    
    if(min_len == 0){
        if(flag){
            return b[half_len];
         }else{
            return 0.5*(b[half_len - 1] + b[half_len]);
         }
    }
    else{
    for(i=0;i<min_len;i++){
        
        if(a[i]<= b[half_len - i -1]){
            if(i == (min_len -1)){
              sort = 1;  
              break;  
            }else{
                  if(b[half_len - i -2] <= a[i+1]){
                      found = i;
                      break;
                }
            }             
        }else{
            if( i==0 ){
                if(flag){
                    return a[0]<b[half_len]?a[0]:b[half_len];
                }else{
                    if(half_len == min_len){
                        return 0.5*(b[half_len - 1] + a[0]);
                    }else{
                        return 0.5*(b[half_len - 1] + (a[0]<b[half_len]?a[0]:b[half_len]));
                    }
                }
            }
        }
        
    
    }
    }
    
    if(!sort){
    if(!flag){
        mid_value = 0.5*((a[found]>b[half_len - found -2]?a[found]:b[half_len - found -2]) + (a[found + 1]<b[half_len - found -1]?     a[found + 1]:b[half_len - found -1]));
    }else{
        mid_value = (a[found + 1]<b[half_len - found -1]?a[found+1]:b[half_len - found -1]);
    }
    
    }
    else{
        if(!flag){
            if(half_len == min_len){
                mid_value = 0.5*(a[half_len -1] + b[0]);
            }else{
                mid_value = 0.5*((a[min_len -1]>b[half_len - min_len -1]?a[min_len -1]:b[half_len - min_len -1]) + b[half_len - min_len]); 
            }
        }else{
           mid_value = b[(nums1Size + nums2Size - 2*min_len)/2]; 
        }
    }
    return mid_value;

}
