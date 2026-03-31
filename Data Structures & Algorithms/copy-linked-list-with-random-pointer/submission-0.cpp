/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> node_map;
        Node dummy_head(0);

        Node *curr = head;
        Node *prev = &dummy_head;

        while(curr != nullptr){
            Node *temp = new Node(curr->val);
            node_map[curr] = temp;
            prev->next = temp;
            prev = temp;
            curr = curr->next;
        }

        curr = head;
        while(curr != nullptr){
            if(curr->random != nullptr){
                node_map[curr]->random = node_map[curr->random];
            }

            curr = curr->next;
        }

        return node_map[head];
    }
};