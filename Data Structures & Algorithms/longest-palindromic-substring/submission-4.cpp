class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        if ( n==1 ) return s;

        string pal = {s[0]};
        vector<vector<bool>> dp( n+1, vector<bool>(n+1, true));

        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                int t = i + j - 1;

                if ( t > n || j + 1 > n ) break;

                if ( s[j-1] != s[t-1] || !dp[j+1][t-1]) {
                    dp[j][t] = false;
                }
                else if ( t-j+1 > pal.size()) {
                    pal = s.substr(j-1, t-j+1);
                }
            }

        return pal;
    }
};
