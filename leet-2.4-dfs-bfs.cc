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
//3 connected part in a picture
void dfs(int x, int y, vector<vecotr<int>>& pic) {
  pic[x][y] = -1;
  for (int i=-1;i<=1;i++) {
    for (int j=-1;j<=1;j++) {
      int nx = x + i, ny = y + j;
      if (nx>=0&&nx<=pic.size()&&ny>=0&&ny<=pic[nx].size()&&pic[nx][ny]>0) dfs(nx, ny, pic);
    }
  }
  return;
}


void bfs(int x, int y, vector<vector<int>>& pic) {
  queue<pair<int, int>> que;
  pic[x][y] = -1;que.push(make_pair(x, y));
  while(!que.empty()) {
    pair<int, int> t = que.front();que.pop();
    for (int i=-1;i<=1;i++) {
      for (int j=-1;j<=1;j++) {
        int nx = t->first + i, ny = t->second + j;
        if (nx>=0&&nx<=pic.size()&&ny>=0&&ny<=pic[nx].size()&&pic[nx][ny]>0) {
          que.push(make_pair(nx, ny));pic[nx][ny]=-1;
        }
      }
    }
  }
}
int solve(vector<vector<int>> pic) {
  int res = 0;
  for (int i=0;i<pic.size();i++) {
    for (int j=0;j<pic[i].size();j++) {
      if (pic[i][j]>0) {
        //dfs(i, j, pic);
        bfs(i, j, pic);
        res ++;
      }
    }
  }
  return res;
}

