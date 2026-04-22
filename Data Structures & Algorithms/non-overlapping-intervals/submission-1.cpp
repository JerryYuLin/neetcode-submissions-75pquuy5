class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int end = intervals[0][0] - 1, n = 0;

        for ( auto interval:intervals ) {
            if ( interval[0] >= end )
                end = interval[1];
            else
                n++;
        }

        return n;
    }
};
