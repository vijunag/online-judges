#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>

using namespace std;

std::vector<char> ops;

enum Operators {
  ADD = 1,
#define OPERATOR_1 +
  SUBTRACT = 2,
#define OPERATOR_2 -
  MULTIPLY = 3,
#define OPERATOR_3 *
  MAX = 4
};

static char GetOpStr(Operators &op)
{
  switch(op) {
   case ADD: return '+';
   case SUBTRACT: return '-';
   case MULTIPLY: return '*';
  }
  return 'Z'; //invalid
}

Operators& operator++(Operators &orig)
{
  orig = static_cast<Operators>(orig+1);
  return orig;
}

Operators operator++(Operators &orig, int val)
{
   Operators res = orig;
   ++orig;
   return res;
}

uint64_t Solve(uint64_t lhs, Operators &op, int rhs)
{
  if (op == ADD)
    return lhs + rhs;
  else if (op == SUBTRACT)
    return lhs - rhs;
  else if (op == MULTIPLY)
    return lhs * rhs;
    
  return 0;
}

int done=0;
int solveExpr(std::vector<int> &elem, uint64_t res, int idx)
{
  if (res&&!(res%101)) {
    done=1;
    return 1;
  }

  if (elem.size()<=idx) {
    return 0;
  }

  for(Operators i=ADD; i<MAX&&!done; i++) {
    uint64_t result = Solve(res, i, elem[idx]);
    ops.push_back(GetOpStr(i));
    if (!solveExpr(elem, result, idx+1)) {
      ops.pop_back();
    }
  }
  return done;
}

int evaluateExpr(std::vector<int> &elem)
{
  solveExpr(elem, 0, 0);

  int k=1;
  for(int i=0;i<elem.size(); ++i) {
    char o;
    printf("%d", elem[i]);
    if (k<ops.size()) {
      o=ops[k++];
    } else {
      o='*';
    }
    if (i!=(elem.size()-1)) {
      printf("%c", o);
    }
  }
  printf("\n");
  return 1;
}

int main(int argc, char **argv) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    std::vector<int> elem;
    char num[10];

#ifdef CMDLINE
    freopen(argv[1], "r", stdin);
#endif /*CMDLINE*/

    scanf("%d\n", &N);
    while (N--) {
      int n, c, k=0;
      scanf("%d", &n);
      elem.push_back(n);
    }
    evaluateExpr(elem); //current idx
    return 0;
}
