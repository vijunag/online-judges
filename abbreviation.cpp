/*Author: Vijay Nag
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;

int dp[1000][1000];

int Abbrev(string a, int m, string b, int n)
{
  if (m>-1&&n>-1&&dp[m][n]!=-1) {
    return dp[m][n];
  }

  if (m==-1 || n==-1) {
    if (n==-1) {
      while (m!=-1) {
        if (std::isupper(a[m])) {
            return 0;
        }
        m--;
      }
      return 1;
    } else {
      return 0;
    }
  }

  if (a[m] == b[n]) {
    dp[m][n] = Abbrev(a,m-1,b,n-1);
  } else if (std::islower(a[m])) {
    dp[m][n]=Abbrev(a,m-1,b,n)||(std::toupper(a[m])==b[n]?Abbrev(a,m-1,b,n-1):0);
  } else {
    dp[m][n]=0;
  }
  return dp[m][n];
}

void initDp(int m, int n)
{
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      dp[i][j]=-1;
}

int main(int argc, char **argv) {
    int q;
#ifdef CMDLINE
  if (argc>1) {
    freopen(argv[1], "r", stdin);
  }
#endif
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string a;
        cin >> a;
        string b;
        cin >> b;
        initDp(a.size(),b.size());
        int res=Abbrev(a,a.size()-1,b,b.size()-1);
        if (res==1) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
    }
    return 0;
}
