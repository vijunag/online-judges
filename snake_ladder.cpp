#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define N 101

int board[N];
int visited[N];

int Bfs(void)
{
  std::queue<int> q;
  int min_count = 0, lmost, done = 0;

  q.push(1); //start from number 1
  visited[1] = 1;
  lmost = 1;

  while (q.size() and !done) {
    int front = q.front();
    q.pop();
    if (lmost == front) {
      lmost = -1;
      min_count++;
    }
    for(int i=1;i<=6 && (front+i)<=100;++i) {
      int node = front+i;
      if (node == 100) {
       visited[100] = 1;
       done = 1;
       break;
      }
      if (!visited[node]) {
        visited[node] = 1;
       if (board[node] != -1) {
         visited[board[node]] = 1;
         node = board[node];
         if (node == 100) {
           visited[100] = 1;
           done = 1;
         }
       }
       if (-1 == lmost)
        lmost = node;
       q.push(node);
      }
     }
   }
  return done ? min_count : -1;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, l, s, i, u, v;

    freopen("input", "r", stdin);
    scanf("%d", &T);

    while (T--) {
      for(i=1;i<N;++i) {
        board[i] = -1;
        visited[i] = 0;
      }

      scanf("%d", &l);
      while(l--) {
        scanf("%d%d", &u, &v);
        board[u] = v;
      }
      scanf("%d", &s);
      while(s--) {
        scanf("%d%d", &u, &v);
        board[u] = v;
      }
      printf("%d\n",Bfs());
    }
    return 0;
}
