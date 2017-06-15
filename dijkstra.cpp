#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define min(a, b) (a) < (b)  ? (a) :(b)
#define INF 100000

using namespace std;
char visited[100000];

int minEdge(std::vector<int> &q, std::vector<int> &dist)
{
    long long min = INF;
    int idx, min_edge_node;

    for (int i = 0; i < q.size(); ++i) {
        if (dist[q[i]] < min ) {
            min = dist[q[i]];
            idx = i;
        }
    }
    idx = idx > q.size() -1 ? q.size() -1: idx;
    min_edge_node = q[idx];
    q.erase(q.begin()+idx);
    return min_edge_node;
}

int dijkstras(std::vector<std::vector<int> > &nodes,
              std::vector<int> &dist, int n,
              int s)
{
    std::vector<int> q;

    for(int i=1; i<=n; ++i) {
        dist[i] = INF;
        q.push_back(i);
        visited[i] = 0;
    }

    dist[s] = 0;

    while (q.size()) {
        int u = minEdge(q, dist);
        visited[u] = 1;

        for (int v=1; v <=n; ++v) {
            if (!visited[v] && nodes[u][v] != -1) {
                int new_dist = dist[u] + nodes[u][v];
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                }
            }
        }
    }
    return 1;
}

int main(){
    int t;

    freopen("input", "r", stdin);
    cin >> t;
    for(int a0 = 0; a0 < t; a0++) {
        int n;
        int m;
        cin >> n >> m;

        std::vector<std::vector<int> > nodes(n+1, std::vector<int>(n+1));
        std::vector<int> dist(n+1);

        for(int i=1;i <=n; ++i) {
          for(int j=1;j<=n;++j){
            nodes[i][j] = -1;
            nodes[j][i] = -1;
          }
        }

        for(int a1 = 0; a1 < m; a1++) {
            int x;
            int y;
            int r;
            cin >> x >> y >> r;
            if (nodes[x][y]==-1) {
                nodes[x][y] = r;
                nodes[y][x] = r;
             } else if (nodes[x][y] > r) {
                nodes[x][y] = r;
                nodes[y][x] = r;
             }
        }

        int s;
        cin >> s;
        dijkstras(nodes, dist, n, s);

        for(int i =1; i <=n; ++i) {
            if (s == i)
                continue;
            if (dist[i] == INF) {
              cout << -1 << " ";
            } else {
              cout << dist[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
