//1 permutation
int x[n]

void bt(int t) {
  if (t == n) {
    print(x);
    return;
  }
  for (int i=t;i<n;i++) {
    swap(x[i], x[t]);
    bt(t+1);
    swap(x[i], x[t]);
  }
}

//2 subset

int x[n];

void bt(int t) {
  if (t == n) {
    print(x);
    return;
  }
  x[i] = 0;bt(t+1);
  x[i] = 1;bt(t+1);
}

