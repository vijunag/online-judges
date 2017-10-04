/*Author: Vijay Nag
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define MAXN 100001
long long N;
std::vector<long long> crank;
int l[MAXN];
int min;

long GetMinCandies(void)
{
  long min=0;

  l[0]=1;
  for(int i=1; i<crank.size(); ++i) {
    l[i]=1;
    if (crank[i]>crank[i-1]) {
      l[i] = l[i-1] + 1;
    }
  }

  for(int i=N-1;i>=0;i--) {
    if (crank[i]<crank[i-1] && l[i-1]<=l[i]) {
      l[i-1]=l[i]+1;
    }
  }

  for(int i=0; i<N; ++i) {
    min+=l[i];
  }
  return min;
}

int main(int argc, char **argv) {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n;

#ifdef CMDLINE
  if (argc>1) {
    freopen(argv[1], "r", stdin);
  }
#endif
  cin >>n;
  N=n;
  while(n--) {
    long long r;
    cin >> r;
    crank.push_back(r);
  }
  std::cout << GetMinCandies() << std::endl;
  return 0;
}
