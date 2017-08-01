#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int sum_of_powers(int sum, int power, int no)
{
    int remaining_sum = sum - pow(no, power);

    if (remaining_sum < 0) {
        return 0;
    } else if (remaining_sum == 0) {
        return 1;
    } else {
        return sum_of_powers(remaining_sum, power, no+1) + //include no
            sum_of_powers(sum, power, no+1); //exclude no
    }
}

int main()
{
    int X, n;
    int *d = NULL;

    scanf("%d", &X);
    scanf("%d", &n);

    printf("%d\n", sum_of_powers(X, n, 1));
}
