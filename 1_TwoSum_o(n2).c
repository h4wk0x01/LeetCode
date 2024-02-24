// --> (github.com/h4wk0x01)


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   
    int* answer;
    answer = (int *) malloc(2 * sizeof(int));

    if (answer == NULL) {
            printf("Memory not allocated.\n");
            exit(0);
    
    }
    
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize; j++){
            if(nums[i] + nums[j] == target && i != j){
                answer[0] = i;
                answer[1] = j;
                *returnSize = 2;
                return answer;
            } 
        }
    }
    
    *returnSize = 0;
    return NULL;
}