//binary search
//1 base binary search 1946-1962， 一个正确的二分法 人类用了16年，当然没有高级语言
int binarySearch(int a[], int n, int t) {
  int i=0, j= n-1;
  while(i<=j) {
    int k = i+(j-i)/2;
    if (t == a[k]) return k;
    if (t>a[k]) i = k+1;
    else j = k-1;
  }
  return -1;
}
// 2 二分法扩展
int solve(vector<int> L,int n, int r) {//n段绳子， 每段长Li， 切割成r个相等的段，可以达到的最大长度
  double lb = 0, ub = max(L)+1;
  for (int i = 0;i< 100;i++) {
    double mid = (lb+ub)/2;
    if (C(mid)) lb = mid;
    else ub = mid;
  }
  return (int)ub;
}

bool C(double x, vector<int> L, int n, int r) {// 判定函数，每段按照x来切分，能切割为多少段
  int num = 0;
  for (int i=0;i<n;i++) {
    num += (int)(L[i]/x);
  }
  return num >= r;
}
