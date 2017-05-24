//https://www.hackerrank.com/challenges/sherlock-and-array

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_ARRAY_ELEMS 1000000
int weights[MAX_ARRAY_ELEMS];

char* solve(int a_size, int* a){
    // Complete this function

    int i = 0;
    int prev_elem = 0;
    int last_elem = weights[a_size-1];

    while (i < a_size) {
        if (prev_elem==(last_elem-weights[i])) {
            return "YES";
        }
				prev_elem = weights[i];
        ++i;
    }
    return "NO";
}

int main() {
    int T;
    scanf("%d", &T);
    for(int a0 = 0; a0 < T; a0++){
        int n;
        scanf("%d", &n);
        int *a = malloc(sizeof(int) * n);
        int sum = 0;

        for(int a_i = 0; a_i < n; a_i++){
           scanf("%d",&a[a_i]);
           sum += a[a_i];
           weights[a_i] = sum;
        }
        int result_size;
        char* result = solve(n, a);
        printf("%s\n", result);
    }
    return 0;
}
