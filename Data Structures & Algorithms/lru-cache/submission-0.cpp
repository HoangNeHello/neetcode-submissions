class LRUCache {
public:
    LRUCache(int capacity) {
        capcty = capacity;
        head = new Node(0, 0); // dummy
        tail = new Node(0, 0); // dummy

        // doubly linked list
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1; // No such key exists

        Node* node = mp[key];
        remove(node); // Take it out from where it is (can be anywhere so we need the map)
        addToFront(node); // Put it at front
        return node->val; 
    }
    
    void put(int key, int value) { 
        // Key already cached: update its value and mark it the most recent one. 
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            remove(mp[key]);
            addToFront(node);
            return;
        }

        // New key, make a node, put it at front, remember it in the map
        Node* node = new Node(key, value);
        addToFront(node);
        mp[key] = node;

        // Over capacity: Evict the least recent (the node just before its tail)
        if (mp.size() > capcty) {
            Node* oldest = tail->prev;
            remove(oldest);
            mp.erase(oldest->key);
            delete oldest;
        }
    }

private: 
    struct Node {
        int key, val; // Key to put into the map
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capcty;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        //A==node==B -> A==B (= here as is doubly linked)
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(Node* node) {
        // Insert right after head: head==X -> head==node==X
        // The order MATTERS because otherwise you might wiring the node to itself (ex. swap the two lines from the rewiring section).
        // Insert first: node now points to X and points backward to head
        node->next = head->next;
        node->prev = head;

        // Rewire later: Cut the connection of head and X
        head->next->prev = node; // X->prev = node (head->next is still X here)
        head->next = node; // now head points to node
    }
};
