class LRUCache {
public:
    deque<int> recent;
    unordered_map<int,int> cache;
    int capacity;
    int curr;
    LRUCache(int capacity) : capacity(capacity) {
        curr = capacity;
    }
    
    int get(int key) {
        if(cache.contains(key)) {
            erase(recent, key);
            recent.push_back(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
         if (cache.contains(key)) {
            cache[key] = value;
            erase(recent, key);
            recent.push_back(key);
            return;
         }

        if (curr != 0) {
            cache[key] = value;
            recent.push_back(key);
            curr--;
            
        } else {
            cache.erase(recent.front());
            recent.pop_front();
            cache[key] = value;
            recent.push_back(key);
        }
    }
};
