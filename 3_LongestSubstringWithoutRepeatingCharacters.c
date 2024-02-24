// --> (github.com/h4wk0x01)

bool isOnStr(char* str, char c, int l){
    int length = l;
    bool flag = 0;
    for(int i = 0; i < length; i++){
        if(str[i] == c){
            flag = 1;
        }
    }
    return flag;
}

int lengthOfLongestSubstring(char* s) {
    int length = strlen(s);
    char *str = (char*) malloc(50000* sizeof(char));
    int index = 0, max = 0;

    int aux = 0;
    for(int i = 0; i < length; i++){
        if(isOnStr(str, s[i], index) == 0){ // if not on substring
            str[index] = s[i];
            index++;
            if(index > max)
                max = index;
        }else{
            i = aux; // reset
            aux++;
            strcpy(str, "");
            index = 0;
        }
    }

    return max;
}