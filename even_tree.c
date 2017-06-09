#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_EDGES 10000

typedef struct Edges {
    int u;  //root
    int v;  //child
} Edges_t;

Edges_t edges[MAX_EDGES];
int node_count[MAX_EDGES/2];
int m, n, i, j, k, u, v;

int removed_edges()
{
    int root = -1, even_count = 0;

    for ( i = 1; i <= n; ++i) {
        if (node_count[i] > root) {
            root = node_count[i];
        }
        if ((node_count[i]%2) ==0)
            even_count++;
    }

    if (root%2 == 0)
        even_count--;
    return even_count;
}

int count_nodes()
{
    for (i =1; i <=n; ++i)
        node_count[i] = 1;

    for (i=m-1; i>=0; --i) {
        node_count[edges[i].v] += node_count[edges[i].u];
    }

    return removed_edges();
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    scanf("%d %d", &n, &m);

    for(i =0; i < m; ++i) {
      scanf("%d %d", &u, &v);
      edges[i].u = u;
      edges[i].v = v;
    }

    printf("%d\n", count_nodes());
    return 0;
}
