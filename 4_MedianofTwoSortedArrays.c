// --> (github.com/h4wk0x01)

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int length = nums1Size + nums2Size;
    int* asw = (int*) malloc(length * sizeof(int));
    bool flag = 1;
    int i = 0, j = 0, k = 0;
    float median = 0.0;
    while(i < (nums1Size) || j < (nums2Size)){
        if(i > (nums1Size-1)){
            asw[k] = nums2[j];
            j++;
        }else if(j > nums2Size-1){
            asw[k] = nums1[i];
            i++;
        }else{
            if(nums1[i] < nums2[j]){
                asw[k] = nums1[i];
                i++;
            }else{
                asw[k] = nums2[j];
                j++;
            }
        }
        k++;
    }
    
    if(length%2 == 0){
        median = (asw[length/2] + asw[(length/2)-1]) / 2.0;
    }else{
        median = asw[(int)length/2];
    }
    
    return median;
}