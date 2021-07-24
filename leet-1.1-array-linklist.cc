int search(vector<int>& arr, int t) {
  int first = 0, last = arr.size();
  while(first!=last) {
    const int mid = (first + last)/2;
    if (arr[mid] == t) return mid;
    if (arr[first]<=arr[mid]) {
      if (arr[first]<=t && arr[mid] > t) {
        last = mid;
      } else {
        first = mid + 1;
      }
    } else {
      if (arr[mid]<target && target <= arr[last-1]) {
        first = mid + 1; 
      } else {
        last = mid;
      }
    }
  }
  return -1;
}

struct RandomListNode {
  int label;
  RandomListNode* next;
  RandomListNode* random;
};
RandomListNode* copy(RandomListNode *head) {
  for (RandomListNode* cur = head; cur != nullptr; ) {
    RandomListNode* node = new RandomListNode(cur->label);
    node->next = cur->next;
    cur->next = node;
    cur = node->next;
  }
  
  for (RandomListNode* cur = head; cur != nullptr; ) {
    if (cur->random != NULL)
      cur->next->random = cur->random->next;
    cur = cur->next->next;
  }

  RandomListNode dummy(-1);
  for (RandomListNode* cur = head, *new_cur = &dummy;cur != nullptr; ) {
    new_cur->next = cur->next;
    new_cur = new_cur->next;
    cur->next = cur->next->next;
    cur = cur->next;
  }
  return dummy.next;
}


class LRUCache {
private:
  struct CacheNode {
    int key;
    int value;
    CacheNode(int k, int v):key(k), value(v) {}
  };
  list<CacheNode> cacheList;
  unordered_map<int, list<CacheNode>::iterator> cacheMap;
  int capacity;
public:
  LRUCache(int capacity) {
    this->capacity = capacity; 
  }
  
  int get(int key) {
    if (cacheMap.find(key) == cacheMap.end()) return -1;
    cahceList.splice(cacheList.begin(), cacheList, cacheMap[key]);
    cacheMap[key] = cacheList.begin();
    return cacheMap[key]->value;
  }
  
  void set(int key, int value) {
    if (cahceMap.find(key) == cacheMap.end()) {
      if (cacheList.size() == capacity) {
        cacheMap.erase(cacheList.back().key);
        cacheList.pop_back();
      }
      cacheList.push_front(cacheList.back().key);
      cacheList.pop_back();
    }
    cacheList.push_front(CacheNode(key, value));
    cacheMap[key] = cacheList.begin();
  } else {
    cacheMap[key]->value = value;
    cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
    cacheMap[key] = cacheList.begin();
  }
}
