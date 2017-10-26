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

using namespace std;

#define MAX 3005

#define INF LONG_MAX

std::vector<long long> a;
long long dp[MAX][MAX];

unsigned long long solve(int n, int k)
{
    if (k>floor(n/2)) {
      k=n-k;
    }
    std::sort(a.begin(), a.end());
    for(int i=0;i<=n;++i)
      for(int j=0;j<=n;++j)
        dp[i][j] = INF;

    dp[0][0]=0;

    for(int i=0;i<n;++i) {
        for(int j=0;j<=i;++j) {
            if (j>k || ((i-j)>(n-k)))
                continue;
            long long li = dp[i][j] + a[i]*(i-j-(n-k-(i-j)));
            long long lu = dp[i][j] + a[i]*(j-(k-j));
            if (dp[i+1][j+1]>li)
                dp[i+1][j+1]=li;
            if(dp[i+1][j]>lu)
                dp[i+1][j]=lu;
        }
    }
    return dp[n][k];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k,c;
    cin >> n >> k;
    c=n;
    while (c--) {
      unsigned long long x;
      cin >> x;
      a.push_back(x);
    }
    cout << solve(n,k) << std::endl;
    return 0;
}
