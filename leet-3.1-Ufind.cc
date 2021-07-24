class Ufind {
private:
  vector<int> par;
public:
  Ufind(int n):par(n) {
    for (int i=0;i<n;i++) par[i] = i;
  }
  int find(int x) {
    if (par[x]!=x) par[x] = find(par[x]);
    return par[x];
  }
  void merge(int x, int y) {
    par[find(x)] = find(y);
  }
};
