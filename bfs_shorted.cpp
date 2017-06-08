#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define min(a, b) (a) == -1 ? b : ((a) < (b) ? (a) : (b))

#define MAX_NODES 1010

int dist_vector[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void Bfs(int n, int s)
{
  std::queue<int> q;

  q.push(s);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    visited[node] = 1;
    for (int i = 1; i <= n; ++i) {
      if (dist_vector[node][i] != -1 && !visited[i]) {
        q.push(i);
        if (dist_vector[s][node] != -1) {
          dist_vector[s][i] = min(dist_vector[s][i], dist_vector[s][node] + dist_vector[node][i]);
        }
      }
    }
  }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q, m, n;

    scanf("%d", &q);

    for( int i = 0; i < q; ++i) {
      int u, v, s;
      scanf("%d %d", &n, &m);
      for (int ii = 1; ii <=n; ++ii) {
        for (int jj = 1; jj <=n; ++jj) {
          dist_vector[ii][jj] = -1;
        }
        visited[ii] = 0;
      }
      for(int j = 0; j < m; ++j) {
        scanf("%d %d", &u, &v);
        dist_vector[u][v] = 6;
        dist_vector[v][u] = 6;
      }
      scanf("%d", &s);
      Bfs(n, s);
      for (int k = 1; k <= n; ++k) {
        if (k != s) {
          printf("%d ", dist_vector[s][k]);
        }
      }
      printf("\n");
    }
    return 0;
}
