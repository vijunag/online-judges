
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>

using namespace std;
#define MAX_STATES 310
int sg[MAX_STATES] = {0,1,2}; //sprague-grundy function
std::vector<int> states;
char pin;

void computeGrundy(void)
{

  for(int i=3;i <=303; ++i) {
    std::set<int> s;
    for(int j=1;j<=2;++j) {
      for(int k=0;k<(i-j)/2+1;++k) {
        s.insert(sg[k]^sg[i-j-k]);
      }
    }
    int m=0;
    while (s.find(m) != s.end()) {
      m++;
    }
    sg[i] = m;
  }
}

int main(int argc, char **argv) {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T, N;

#ifdef CMDLINE
  if (argc>1) {
    freopen(argv[1], "r", stdin);
  }
#endif
  computeGrundy();
  cin >> T;
  while(T--) {
    cin >> N;
    states.clear();
    int count = 0;
    for(int i=0;i<N;i++) {
      cin>>pin;
      if (pin=='I') {
        count++;
      } else {
        if (count)
          states.push_back(count);
        count=0;
      }
    }
    states.push_back(count); //last group of one's
    int m=0;
    for(int i=0;i<states.size();++i) {
      m^=sg[states[i]];
    }
    if (m) {
      printf("WIN\n");
    } else{
      printf("LOSE\n");
    }
  }
  return 0;
}
