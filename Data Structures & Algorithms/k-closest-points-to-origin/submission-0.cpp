class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct CustomCompare {
            bool operator()(const pair<double, vector<int>>& a, const pair<double, vector<int>>& b) {
                return a.first < b.first; 
            }
        };
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, CustomCompare> maxHeap;

        for(vector<int> point:points) {
            maxHeap.push({sqrt(point[0]*point[0] + point[1]*point[1]), point});

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
