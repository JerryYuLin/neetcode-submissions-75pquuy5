class Solution {
public:
    int rob(vector<int>& nums) {
        if ( nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp;

        for ( int i = 0 ; i < nums.size() ; ++i ) {
            int a = 0, b = 0;

            if ( i - 2 >= 0) {
                a = dp[i-2];
            }
            if ( i - 3 >= 0) {
                b = dp[i-3];
            }

            dp.push_back(max( a + nums[i], b + nums[i] ));
        }

        int n = dp.size();
        return max( dp[n-1], dp[n-2] );
    }
};
