// Scratch implementation
// Hint: use list stl


struct Node{
        int val;
        int key;
        Node *next;
        Node *prev;
        Node(int key, int value) : val(value), key(key), next(NULL), prev(NULL){}
    };
    
class LRUCache {
    unordered_map<int, Node*> keyMap;
    Node *head, *tail;
    int filled;
    int capacity;
    
public:
    LRUCache(int capacity): capacity(capacity), filled(0){
        
    }
    
    int get(int key) {
        if(filled == 0) return -1;
        if(keyMap.find(key) == keyMap.end()) return -1;
        if(capacity == 1 || head->key == key) return keyMap[key]->val;
        
        Node *current = keyMap[key];
        current->prev->next = current->next;
        if(current->next != NULL) current->next->prev = current->prev;
        else tail = current->prev;
        current->next = head;
        head->prev = current;
        current->prev = NULL;
        head = current;
        
        return current->val;
    }
    
    void put(int key, int value) {
         if(keyMap.find(key) != keyMap.end()){
                cout << "in here" << key << value<< endl;
                this->get(key);
                head->val = value;
                keyMap[key] = head;
             return;
            }
        if(filled == 0){
            head = new Node(key, value);
            tail = head;
            keyMap[key] = head;
            filled++;
        }
        else if(filled == capacity){
            int prvKey = tail->key;
            int prvVal = tail->val;
            Node *current = tail;
            this->get(prvKey);
            head->val = value;
            head->key = key;
            
//             if(head == tail) {
            //head->val = value;
//                 head->key = key;
//                 
//             }
           
//             else{
//                 tail = tail->prev;
//                 tail->next = NULL;
//                 current->prev = NULL;
//                 current->next = head;
//                 head->prev = current;
//                 head = current;
//                 head->val = value;
//                 head->key = key;
//             }
            keyMap.erase(prvKey);
            keyMap[key] = head;
        }
        else{
            
            Node *current = new Node(key, value);
            current->next = head;
            head->prev = current;
            head = current;
            keyMap[key] = head;
            filled++;
            
        }
        
        
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */