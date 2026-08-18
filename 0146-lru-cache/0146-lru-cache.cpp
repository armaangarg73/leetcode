class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head; // newest
    Node* tail; // oldest

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }

    void moveToFront(Node* node) {

        if (node == head)
            return;

        // Remove node from current position
        if (node->prev)
            node->prev->next = node->next;

        if (node->next)
            node->next->prev = node->prev;

        if (node == tail)
            tail = node->prev;

        // Insert node at front
        node->prev = NULL;
        node->next = head;

        if (head)
            head->prev = node;

        head = node;

        if (!tail)
            tail = head;
    }
    
    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        moveToFront(node);

        return node->value;
    }
    
    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            moveToFront(node);

            return;
        }

        // Cache full
        if (mp.size() == capacity) {

            Node* node = tail;

            mp.erase(node->key);

            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                tail = tail->prev;
                tail->next = NULL;
            }

            delete node;
        }

        // Create new node
        Node* node = new Node(key, value);

        // Insert at front
        node->next = head;

        if (head)
            head->prev = node;

        head = node;

        if (!tail)
            tail = node;

        mp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */