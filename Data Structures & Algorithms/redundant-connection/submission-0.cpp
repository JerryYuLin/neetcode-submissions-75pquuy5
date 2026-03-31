class Solution {
public:
    vector<int> parent;

    int find(int i) {
        if (parent[i]==i) return i;
        
        parent[i] = find(parent[i]);

        return parent[i];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 0; i<=edges.size(); ++i) {
            parent.push_back(i);
        }
        for (vector<int>& edge:edges) {
            int u = edge[0], v = edge[1];

            if (find(u) == find(v)) {
                return edge;
            }
            else {
                parent[find(v)] = find(u);
            }
        }
        return {};
    }
};
