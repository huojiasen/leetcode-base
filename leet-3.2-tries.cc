struct Node {
  vector<Node*> child = vector<Node*>(26, NULL);
  bool is_end = false;
};

class Treis {
private:
  Node* root = new Node();
public:
  void insert(string w) {
    Node* r = root;
    for (char c:w) {
      if (r->child[c-'a']==NULL) {
        r->child[c-'a'] = new Node();
      }
      r = r->child[c-'a'];
    }
    r->is_end = true;
  }
  bool search(String w) {
    Node* r = root;
    for (char c:w) {
      if (r->child[c-'a']==NULL) return false;
      r = r->child[c-'a'];
    }
    return r->is_end;
  }
  
};
