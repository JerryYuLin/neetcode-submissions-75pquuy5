/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        Node* n = new Node(node->val);
        visited[node] = n;

        for (Node* temp:node->neighbors) {
            Node* t;
            
            if (visited.contains(temp)) t = visited[temp];
            else t = cloneGraph(temp);

            n->neighbors.push_back(t);
        }

        return n;
    }
private:
    unordered_map<Node*, Node*> visited;
};
