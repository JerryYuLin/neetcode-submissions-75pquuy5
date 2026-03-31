class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int n = nums.size();
        vector<int> dp = {nums[0], max(nums[0], nums[1])};

        for (int i = 2; i < n-1; ++i) {
            dp.push_back(max( dp[i-1], nums[i] + dp[i-2] ));
        }

        int max1 = dp[dp.size()-1];
        dp = {nums[1], max(nums[1], nums[2])};

        for (int i = 2; i < n-1; ++i) {
            dp.push_back(max( dp[i-1], nums[i+1] + dp[i-2] ));
        }

        int max2 = dp[dp.size()-1];
        return max(max1, max2);
    }
};
