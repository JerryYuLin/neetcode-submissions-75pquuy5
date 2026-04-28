class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp = {1};
        int n = s.size();

        if ( s[0] != '0' )
            dp.push_back(1);
        else
            return 0;

        if ( n == 1 )
            return dp[1];
    
        for ( int i = 2; i <= n; ++i ) {
            int num = (s[i-1]-'0') + (s[i-2]-'0') * 10;
            int count = 0;

            if ( s[i-1] != '0' )
                count += dp[i-1];

            if ( s[i-2] != '0' && num <= 26 )
                count += dp[i-2];

            dp.push_back(count);
        }

        return dp[n];
    }
};
