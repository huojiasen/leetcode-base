//stack-opt 使用栈优化一类问题，把O(n*n) 优化为 O(n)
//经典 直方图最大矩阵
int fmax(vector<int>& h) {
  vector<int> L(h.size(), 0), R(h.size(), 0);
  stack<int> st;int n = h.size();
  for (int i=0;i<n;i++) {
    while(!st.empty() && h[st.top()]>=h[i]) st.pop();
    if (st.empty()) L[i] = 0;
    else L[i] = st.top() + 1;
    st.push(i);
  }
  st.clear();
  for (int i=n-1;i>=0;i--) {
    while(!st.empty()&&h[st.top()]>=h[i]) st.pop();
    if (st.empty()) R[i] = n;
    else R[i] = st.top();
    st.push(i)
  }
  
  int res = 0;
  for (int i=0;i<n;i++) {
    res = max(res, h[i]*(R[i] - L[i]));
  }
  return res;
}

