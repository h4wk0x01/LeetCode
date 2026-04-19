class Solution {
public:

    string longestPalindrome ( string s ){

        // EXPAND FROM CENTER

        int length = s.length();
        int size = 0;
        int maxSize = 1;
        int left, right = 0;
        string response = "";
        response += s[0];

        if( length == 1 ){
            return response;
        }

        auto expand = [&]( int left, int right ) {
            while( left >= 0 && right < length && s[left] == s[right]){
                size = right - left + 1;
                string sub = s.substr(left, size);
                if( size > maxSize ){
                    maxSize = size;
                    response = sub;
                }
                left--;
                right++;
            }
        };

        for ( int i = 0; i < length; i++ ) {
            expand(i, i);
            expand(i, i+1);
        }
        
        return response;
    }
};
