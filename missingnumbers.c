
//https://www.hackerrank.com/challenges/missing-numbers
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXLISTSIZE 10000000

int comparer(const void *l, const void *r)
{
    int lhs = *(int*)l;
    int rhs = *(int*)r;

    if (lhs < rhs)
        return -1;
    else if (lhs > rhs)
        return 1;
    return 0;
}

int a[MAXLISTSIZE], b[MAXLISTSIZE];

int main() {
    int m,n, i,j;

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    for (i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }

    qsort(&a[0], n, sizeof(a[0]), comparer);
    qsort(&b[0], m, sizeof(b[0]), comparer);

    for ( i = 0, j = 0; j < m;) {
        if (a[i]!=b[j]) {
         printf("%d ", b[j]);
         while(b[j] == b[j+1])
           j++;
        } else {
          ++i;
        }
        j++;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
