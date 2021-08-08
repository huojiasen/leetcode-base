// 滑动窗口，最短的连续字段和大于S， O(n*n)--> O(n)
void solve(vector<int> a, int S) {
  int res = a.size()+1, s = 0, e = 0, sum = 0;
  while(true) {
    while(e<n && sum<S) sum += a[e++];
    if(sum<S) break;
    res = min(res, e-s);
    sum -= a[s++];
  }
  return res;
}
