class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();

        // 1. 左邊：所有在 newInterval 之前的區間 (完全沒重疊)
        // 條件：舊區間的結尾 < newInterval 的開頭
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // 2. 中間：處理所有會重疊的區間，並合併成一個大的 newInterval
        // 條件：舊區間的開頭 <= newInterval 的結尾 (只要這個成立，就一定有重疊)
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval); // 把合併完的超級區間丟進去

        // 3. 右邊：剩下所有在 newInterval 之後的區間
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};