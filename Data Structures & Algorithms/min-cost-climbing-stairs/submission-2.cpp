class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> t = {0, 0};
        int n = cost.size();

        for (int i=2; i<n; ++i) {
            t.push_back(min((t[i-2] + cost[i-2]), (t[i-1] + cost[i-1])));
        }

        return min((t[n-2] + cost[n-2]), (t[n-1] + cost[n-1]));
    }
};
