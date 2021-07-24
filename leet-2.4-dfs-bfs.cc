const int n = 100;
vector<int> G[n]
bool visited[n]

void dfs(vector<int>* g, int v) {
  cout<<v<<endl;
  visited[v] = 1;
  for (int i=0;i<g[v].size();i++) {
    if (visited[g[v][i]] == 0) {
      dfs(g, g[v][i]);
    }
  }
}

void bfs(vector<int>* g, int v) {
  queue<int> que;
  cout<<v<<endl;
  visited[v] = 1;
  que.push(v);
  while(!que.empty()) {
    int t = que.front();que.pop();
    for (int i=0;i<g[t].size();i++) {
      if (visited[g[t][i]]==0) {
        cout<<g[t][i]<<endl;
        visited[g[t][i]] = 1;
        que.push(g[t][i]);
      }
    }
  }
}
