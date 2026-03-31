class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n);

        for (vector<int>& edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int c = 0;
        for (int i=0; i<n; ++i)
            if (!visited[i]) {
                ++c;
                dfs(i, adj, visited);
            }

        return c;
    }

    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[i] = true;

        for (int n:adj[i]) {
            if (!visited[n]) dfs(n, adj, visited);
        }
    }
};
