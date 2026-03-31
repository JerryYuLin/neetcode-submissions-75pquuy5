class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct CustomCompare {
            bool operator()(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
                return a.first < b.first; 
            }
        };
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, CustomCompare> maxHeap;

        for(vector<int> point:points) {
            maxHeap.push({point[0]*point[0] + point[1]*point[1], point});

            while(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans;
        
        while(maxHeap.size() > 0) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};
