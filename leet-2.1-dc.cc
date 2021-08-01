//divide & conquer

//1 a的n次方
double f(double a, int n) {
  double res = 1.0;
  while(n!=0) {
    if (n&1) res = res * a;
    a = a*a;
    n>>=1;
  }
  return res;
}
