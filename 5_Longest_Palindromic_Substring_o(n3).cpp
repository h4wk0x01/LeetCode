class Solution {
public:

    bool isPalindrome ( int left, int right, string s ){

        bool response = true;

        if( left < right ){
            if ( s[left] != s[right] ){
                return false;
            }
            response = isPalindrome ( left+1, right-1, s );
        }
        return response;
    }


    string longestPalindrome ( string s ){

        /*
                        01234
            Input: s = "babab"
                        L
                            R
            0123
            cbbd
              L
               R
        */

        int length = s.length();
        int left = 0;
        int right = length-1;
        int highest = 1;
        string response = "";

        if( length == 1 ) {
            response += s[0];
            return response;
        }

        response += s[0];

        int size = 0;
        while ( left < length ) {
            right = length-1;
            while ( right > left ) {
                size = right-left+1;                
                if ( size > highest ) {
                    string substr = s.substr(left, size);
                    if ( isPalindrome(0, size-1, substr) ) {
                        highest = size;
                        response = substr;
                        right = left; // no need to continue decreasing curr str
                    }                    
                }
                right--;
            }
            left++;
        }
        return response;
    }
};
