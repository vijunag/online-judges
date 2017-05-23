
//https://www.hackerrank.com/challenges/minimum-loss

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

#define MIN_LOSS 0xFFFFFFFF
#define MAX_PRICE_ARRAY 1000000
uint64_t prices[MAX_PRICE_ARRAY];

typedef struct val_idx_info {
int idx;
uint64_t price;
} val_idx_info_t;

val_idx_info_t sorted_prices[MAX_PRICE_ARRAY];

int comparer(const void *lhs, const void *rhs)
{
    uint64_t l = ((val_idx_info_t*)lhs)->price;
    uint64_t r = ((val_idx_info_t*)rhs)->price;

    if (l < r)
        return -1;
    else if (l > r)
        return 1;
    else
        return 0;
}

int main() {
  int n, i , j;
  uint64_t min_loss = MIN_LOSS;

  scanf("%d", &n);

  for (i = 0; i < n; ++i) {
      scanf("%lu", &prices[i]);
      sorted_prices[i].idx = i;
      sorted_prices[i].price = prices[i];
  }

  qsort(&sorted_prices[0], n, sizeof(sorted_prices[0]), comparer);

  for ( i = 0; i < n; ++i) {
    if ((sorted_prices[i+1].price - sorted_prices[i].price) < min_loss &&
         sorted_prices[i+1].idx < sorted_prices[i].idx)
              min_loss = sorted_prices[i+1].price - sorted_prices[i].price;
  }
  printf("%lu\n", min_loss);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
