#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/* Head ends here */
//https://www.hackerrank.com/challenges/pairs
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

int pairs(int a_size, int* a, int k) {

   int ans = 0, i = 0, j = 0;

    /* Write your code here */
    printf("Number of elements to sort %d\n", a_size);
    qsort((void*)a, a_size, sizeof(int), comparer);

    while (j < a_size) {
        if ((a[j] - a[i]) > k) {
          i++;
        } else if ((a[j]-a[i]) < k) {
          j++;
        } else if ((a[j] - a[i]) == k) {
          ans++;
          j++;
        }
    }

   return ans;
}

/* Tail starts here */
int main() {
    int res;

    freopen("input", "r", stdin);
    int _a_size,_a_i,_k;
    scanf("%d %d", &_a_size,&_k);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) {
        int _a_item;
        scanf("%d", &_a_item);

        _a[_a_i] = _a_item;
    }
   res=pairs(_a_size,_a,_k);
   printf("%d\n",res);
    return 0;
}
