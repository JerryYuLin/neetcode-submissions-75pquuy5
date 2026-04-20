class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0]; });
        vector<vector<int>> vec;

        vector<int> temp = intervals[0];
        int i = 1, n = intervals.size();

        while ( i < n ) {
            if ( temp[1] >= intervals[i][0] ) {
                temp[0] = min( temp[0], intervals[i][0] );
                temp[1] = max( temp[1], intervals[i][1] );
                i++;
            }
            else {
                vec.push_back(temp);
                temp = intervals[i];
                i++;
            }
        }
        vec.push_back(temp);

        return vec;
    }
};
