//dynamic programming
//1
int maxSubArray(int A[], int n) {
  int result = INT_MIN, f = 0;
  for (int i = 0; i < n; ++i) {
    f = max(f + A[i], A[i]);
    result = max(result, f);
  }
  return result;
}
//2 
int minDistance(const string &word1, const string &word2) { 
  int n = word1.size(), m = word2.size();
  
  for (int i = 0; i <= n; i++) f[i][0] = i;
  for (int j = 0; j <= m; j++) f[0][j] = j;
  
  int f[n + 1][m + 1];       
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (word1[i - 1] == word2[j - 1])
        f[i][j] = f[i - 1][j - 1];
      else {
        int mn = min(f[i - 1][j], f[i][j - 1]);
        f[i][j] = 1 + min(f[i - 1][j - 1], mn);
      } 
    }
  }
  
  return f[n][m];
}

//3 nlog(n) 的方法
void Lis(int a[], int n) {
  fill(a, a + n, INF);
  for (int i=0;i<n;i++) {
    *lower_bound(a, a+n, a[i]) = a[i];
  }
  cout<< lower_bound(a, a + n, INF) - a<<end;
}
