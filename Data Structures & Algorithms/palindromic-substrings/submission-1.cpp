class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        if ( n == 1 ) {
            return 1;
        }
        
        int count = n;
        vector<vector<bool>> dp( n+2, vector<bool>( n+2, true));

        for ( int i = 2; i <= n; ++i )
            for ( int j = 1; j+i-1 <= n; ++j ) {
                if ( dp[j+1][j+i-2] && s[j-1] == s[j+i-2] ) {
                    ++count;
                }
                else {
                    dp[j][j+i-1] = false;
                }
            }
        
        return count;
    }
};
