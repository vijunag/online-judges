#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <map>

#define MAX(a,b) (a) > (b) ? (a) : (b)
#define MIN(a,b) (a) < (b) ? (a) : (b)
std::vector<uint64_t> S; // Set of numbers
std::map<uint64_t, uint64_t> M; //number set
using namespace std;

uint64_t stoneDiv(std::vector<uint64_t> &s, uint64_t n)
{
    uint64_t max_moves = 0;
    std::map<uint64_t, uint64_t>::iterator it = M.find(n);

    if (n == 1)
      return 0;

    if (it != M.end()) {
      return it->second;
    }
    for(int i=0; i<s.size(); ++i) {
        if ((n!=s[i])&&!(n%s[i])){
            uint64_t m = 1;
            m+=(n/s[i])*stoneDiv(s,s[i]);
            max_moves = MAX(max_moves, m);
        }
    }
    M[n] = max_moves;
    return max_moves;
}

int main(int argc, char **argv) {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  uint64_t n, q, m;

#ifdef CMDLINE
  if (argc>1) {
      freopen(argv[1], "r", stdin);
  }
#endif /*CMDLINE*/

  cin >> q;
  while(q--) {
    S.clear();
    M.clear();
    cin >> n >> m;
    while(m--) {
        uint64_t x;
        cin >> x;
        S.push_back(x);
    }
    printf("%lu\n", stoneDiv(S, n));
  }
  return 0;
}
