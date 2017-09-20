#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <set>

#define MIN(a,b) (a) < (b) ? (a) : (b)

using namespace std;
std::vector<uint64_t> LexStack;
std::vector<uint64_t> stack;
std::vector<uint64_t> A; //list of numbers
std::set<uint64_t> result;

void lexSmallest()
{
  if ((LexStack.size() == 0) || (LexStack.size()>stack.size())) {
    LexStack = stack;
  } else { //break the ties here
    int m = stack.size();
    int n = LexStack.size();
    if (m<n) {
      for(int i=0;i<m;++i) {
        if (stack[i]!=LexStack[i]) {
          goto done;
        }
      }
      int k = MIN(m, n);
      if (stack[k+1]<LexStack[k+1]) {
        for(int i=0;i<k;++k) {
          if (stack[k+1]!=LexStack[k+1]) {
            goto done;
          }
        }
      }
      LexStack=stack;
    }
  }
done: //LexStack is lexicographically small already
  return;
}

int factorize(uint64_t n, uint64_t res)
{
  if (res==n) {
    lexSmallest();
    stack.pop_back();
    return 1;
  }
    
  if(result.find(res)!=result.end()) {
      return 0;
  }

  for(int i=0;i<A.size();++i) {
     if (res*A[i]<=n) {
       stack.push_back(A[i]);
       if(!factorize(n, res*A[i])) {
         stack.pop_back();
       }
     }
  }
  result.insert(res);
  return 0;
}

int main(int argc, char **argv) {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  uint64_t N, K;
#ifdef CMDLINE
  if (argc>1) {
    freopen(argv[1], "r", stdin);
  }
#endif /*CMDLINE*/

  cin >> N >> K;

  while(K--) {
    uint64_t a;
    cin >> a;
    A.push_back(a);
  }
  factorize(N, 1);
  uint64_t mul = 1;
  if (LexStack.size()) {
    cout << mul << " "; //initial one
    for(int i=0;i<LexStack.size();++i) {
      mul *=LexStack[i];
      cout << mul << " ";
    }
  } else {
    cout << "-1";
  }
  cout << std::endl;
  return 0;
}
