// 简单的kmp算法 生成next数组，依次计算，复杂度不变，结构更清晰
vector<int> getNext(string t) {
  vector<int> next(t.size(), 0);
  next[0] = -1;
  for(int i=1;i<t.size();i++) {
    int k = next[i-1];
    while(true) {
      if (k==-1||t[k] == t[i-1]) {
        next[i] = k+1;
        break;
      }
      else k = next[k];
    }
  }
  return next;
}
