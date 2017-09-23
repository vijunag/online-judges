#include <bits/stdc++.h>

using namespace std;

long  getWays(long n, vector < long > c){
    // Complete this function
    int m = c.size();
    long count[n+1][m];
    
    for (int i=0; i < m; ++i)
        count[0][i] = 1;
    
    for(int i = 1; i<n+1; ++i) {
        for (int j = 0; j < m; ++j) {
            long x = (i-c[j] >= 0) ? count[i-c[j]][j] : 0;
            long y = j>= 1 ? count[i][j-1] : 0;
            count[i][j] = x+y;
        }
    }
    return count[n][m-1];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    cout << ways << std::endl;
    return 0;
}
