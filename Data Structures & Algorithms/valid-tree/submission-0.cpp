class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> states(n, 0);
        vector<vector<int>> nodes(n);

        for (vector edge:edges) {
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }

        if (hasCycle(0, nodes, states, -1)) return false;

        for (int state:states)
            if (state == 0) return false;

        return true;
    }

    bool hasCycle (int i, vector<vector<int>>& nodes, vector<int>& states, int parent) {
        states[i] = 1;

        for (int node:nodes[i]) {
            if (node == parent) continue;
            else if (states[node] == 1) {
                return true;
            }
            else if (states[node] == 0 && hasCycle(node, nodes, states, i)) return true;
        }

        states[i] = 2;
        return false;
    }
};
