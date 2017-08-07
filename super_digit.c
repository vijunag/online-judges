#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long sum_digit(unsigned long long num)
{
    unsigned long long sum = 0;

    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int super_digit(unsigned long long num)
{
    if (num >0 && num <10)
        return num;

    return super_digit(sum_digit(num));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long long N, K, P;
    char c;
    int i = 0;

    N = 0, K=0;
    while (isdigit((c=getchar()))) {
        N += c - '0';
    }

    while (isdigit((c=getchar()))) {
        K = K * pow(10, i++);
        K += (c-'0');
    }
    P = sum_digit(N) * K;

    printf("%d", super_digit(P));
    return 0;
}
