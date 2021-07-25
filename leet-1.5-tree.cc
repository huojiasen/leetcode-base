//tree

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
  vector<int> res;
  stack<TreeNode*> st;
  TreeNode* p = root;
  while(!st.empty()||p) {
    if (p) {
      st.push(p);p = p->left;
    } else {
      p = st.top();st.pop();
      res.push_back(p->val);
      p = p->right;
    }
  }     
  return res;
}
void inorder(TreeNode* root, vector<int>& res) {
  if (root!=NULL) {
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
  }
}
