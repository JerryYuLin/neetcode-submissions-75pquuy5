class LRUCache {
public:
    struct node {
        int key;
        int val;
        node *next;
        node *prev;

        node(int k,int x): key(k), val(x), next(nullptr), prev(nullptr) {}
    };

    unordered_map<int, node*> node_map;
    node* head;
    node* tail;
    int max_capacity;

    LRUCache(int capacity) {
        max_capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }

    void updateDLL(node *target){
        // connect prev and next
        node *p = target->prev;
        node *n = target->next;

        if(p == nullptr){
            return;
        }
        else if(n == nullptr) {
            p->next = nullptr;
            tail = p;
        }
        else {
            p->next = n;
            n->prev = p;
        }

        head->prev = target;
        target->next = head;
        target->prev = nullptr;

        head = target;
    }
    
    int get(int key) {
        if (node_map.count(key) > 0){
            node *target = node_map[key];

            updateDLL(target);

            return target->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(node_map.count(key) > 0) {
            node *target = node_map[key];
            target->val = value;
            updateDLL(target);
        }
        else {
            if(node_map.size() == max_capacity){
                if(tail->prev != nullptr){
                    node *tail_prev = tail->prev;
                    tail_prev->next = nullptr;
                    node_map.erase(tail->key);
                    delete tail;
                    tail = tail_prev;
                }
                else {
                    node_map.erase(tail->key);
                    delete tail;
                    tail = nullptr;
                    head = nullptr;
                }
            }
            
            if(node_map.size() != 0){
                node *newNode = new node(key, value);
                node_map[key] = newNode;
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            else {
                node *newNode = new node(key, value);
                node_map[key] = newNode;
                head = newNode;
                tail = newNode;
            }
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */