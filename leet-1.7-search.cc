//search
//1 bst balance tree avl rb-tree
#include <map>
void test_bst() {
  map<int, int> m;
  m.insert(make_pair<int, int>(1, 10));
  auto it = m.find(1);
  if (it!=m.end()) {
    cout<< it->second;
  }
}
// 2 hash table
#include <unordered_map>
void test_hash_table() {
  unordered_map<int, int> m;
  m.insert(make_pair<int, int>(1, 10));
  auto it = m.find(1);
  if (it!=m.end()) {
    cout<< it->second;
  }
}
