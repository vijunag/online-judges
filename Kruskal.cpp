#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <stdlib.h>

using namespace std;

#define MAX_EDGES (3000 * 2999)/2
#define MAX_NODES 3000

int set[MAX_NODES];

typedef struct Edges {
  int u;
  int v;
  int r;
} Edges;

static int comparer(const void *lhs, const void *rhs)
{
  Edges *l = (Edges*)lhs;
  Edges *r = (Edges*)rhs;
  int lweight = l->r;
  int rweight = r->r;

  if (l->r == r->r) {
    lweight = l->u + l->r + l->v;
    rweight = r->u + r->r + r->v;
  }
  return lweight < rweight ? -1 : 1;
}

void MakeSet(Edges *e, int n)
{
  for (int i = 1; i <= n; ++i) {
    set[i] = i;
  }
}

int FindSet(int x)
{
  int xnode = x;

  while (set[xnode] != xnode) {
    xnode = set[xnode];
  }
  return xnode;
}

void Union(int x, int y)
{
  int xroot = FindSet(x);
  int yroot = FindSet(y);

  if (xroot != yroot) {
    set[yroot] = xroot;
  }
}

uint64_t FindSpanningDistance(Edges *e, int n, int m)
{
  uint64_t x = 0;

  MakeSet(e, n);
  for (int i = 0; i < m; ++i) {
    if (FindSet(e[i].u) != FindSet(e[i].v)) {
      x += e[i].r;
    }
    Union(e[i].u, e[i].v);
  }

  return x;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m, u,v, r;

    scanf("%d %d", &n, &m);
    Edges *e = new Edges[m];

    for (int i=0; i < m; ++i) {
      scanf("%d %d %d\n", &e[i].u, &e[i].v, &e[i].r);
    }

    qsort(e, m, sizeof(Edges), comparer);
    printf("%llu\n", FindSpanningDistance(e, n, m));
    return 0;
}
