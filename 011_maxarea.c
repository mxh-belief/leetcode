// int maxArea(int* height, int heightSize) {
    
//     int i, j;
//     int h,maxarea=0,curr_area = 0;
    
//     if(heightSize ==0 || heightSize == 1){
//         return 0 ;
//     }
    
//     for(i=0;i<heightSize;i++){
//         for(j=0;j<i;j++){
//             h = height[i]<height[j]?height[i]:height[j];
//             curr_area = h * (i - j);
//             maxarea = maxarea<curr_area?curr_area:maxarea;
//         }
//     }
    
    
//     return maxarea;
    
// }

int maxArea(int* height, int heightSize) {
    
    
   if(heightSize ==0 || heightSize == 1){
        return 0 ;
    }
    
    int i = 0, j = heightSize -1;
    int h,maxarea=0,curr_area = 0;
    
    while(i<j){
        h = height[i]<height[j]?height[i]:height[j];  
        curr_area = h * (j - i);
        maxarea = maxarea<curr_area?curr_area:maxarea;
        if(height[i]<height[j]){
            i++;
        }else{
            j--;
        }
    }
    
    
    return maxarea;
    
}
