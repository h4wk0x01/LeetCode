class Solution {
public:
    bool isPalindrome(int x) {
        /*
        12321
        R
            L

        121
         RL
        */

        string str = to_string(x);

        int length = str.length();
        int right = length-1;
        int left = 0;

        while( left < right ){
            if( str[left] != str[right] ){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
