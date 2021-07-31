//binary search
//1 base binary search 1946-1962
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
