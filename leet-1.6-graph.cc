//graph
//1 dfs & bfs
const int n = 100;
vector<int> G[n];
bool visited[n];
int cost[n][n];

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

// 2 dijkstra & floyd
int dist1[n];
void dijkstra(int s) {
  dist[s] = 0;
  while(true) {
    int v = -1;
    for (int i=0;i<n;i++) {
      if (!visited[i]&&(v==-1||dist[i]<dist[v])) v = i;
    }
    
    if (v == -1) break;
    used[v] = true;
    for (int i=0;i<g[v].size();i++)
       dist[i] = min(dist[i], dist[v]+g[v][i]);
  }
}

int dist2[n][n];
void floyd() {
  for (int k = 0;k<n;k++) 
     for (int i=0;i<n;i++)
       for (int j=0;j<n;j++) dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
}

// 3 prim kruskal max-flow bi-graph
// maybe too hard for interview, just give up

