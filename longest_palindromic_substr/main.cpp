#include <iostream>
#include <vector>
#include <string>

class Solution {
    public:
        std::string longestPalindrome( std::string s )
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl;

            int n = s.size(), start, max_len = 0;
            if( n == 0 ) return "";

            std::vector<std::vector<bool>> dp( n, std::vector<bool>( n, false ) );
            for( int i = 0; i < n; ++i ) dp[i][i] = true;
            for( int i = 0; i < n - 1; ++i ) dp[i][i + 1] = s[i] == s[i + 1];
            for( int i = n - 3; i >= 0; --i )
            {
                for( int j = i + 2; j < n; ++j )
                {
                    dp[i][j] = ( dp[i + 1][j - 1] ) && ( s[i] == s[j] );
                }
            }
            for( int i = 0; i < n; ++i )
            {
                for( int j = i; j < n; ++j )
                {
                    if( dp[i][j] && j - i + 1 > max_len )
                    {
                        max_len = j - i + 1;
                        start = i;
                    }
                }
            }

            return s.substr( start, max_len );
        }
};

int main( void )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    Solution* s = new Solution();

    std::cout << s->longestPalindrome( "babad" ) << std::endl;
    return true;
}