/*Author: Vijay Nag
 */
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

#define MAX(a,b) (a) > (b) ? (a) : (b)
#define MIN(a,b) (a) < (b) ? (a) : (b)
#define MAX_STR_SIZE 300
#define WIN 1000
#define LOSE -WIN

using namespace std;
typedef std::bitset<MAX_STR_SIZE> BitMap;
char pin;

static void PrintGameBoard(BitMap &b, int n)
{
  for(int i=n;i>=0;--i) {
    if(b.test(i)) {
      printf("I");
    } else {
      printf("X");
    }
  }
  printf("\n");
}

int GameScore(BitMap &b, int max)
{
  int count = b.count();
  count=count==0 ? WIN : 0;
  return max ? -count : count;
}

int minimax(BitMap b, int N, int alpha, int beta, int max)
{
  int score=GameScore(b, max);
#ifdef DEBUG
  printf("Ply=%d, max=%d, score=%d\n", depth,
      max, score);
  PrintGameBoard(b, N);
#endif /*DEBUG*/

  if (WIN==std::abs(score)) {
    return score;
  }

#define PRUNE(func, _a, _b, _op)\
  _op=func(_op, score);         \
  if (_b<=_a) {                 \
    break;                      \
  }                             \

  if(max) {
    int score=LOSE;
    int v;
    for(int i=N;i>=0;--i) {
      if (b.test(i)) {
        b.reset(i);
        v=minimax(b,N,alpha,beta,0);
        score=MAX(score,v);
        PRUNE(MAX, alpha, beta, alpha);
        if((i-1)>=0 && b.test(i-1)) {
          b.reset(i-1);
          v=minimax(b,N,alpha,beta,0);
          b.set(i-1);
          score=MAX(score,v);
          PRUNE(MAX, alpha, beta, alpha);
        }
        if((i+1)<=N && b.test(i+i)) {
          b.reset(i+1);
          v=minimax(b,N,alpha,beta,0);
          b.set(i+1);
          score=MAX(score,v);
          PRUNE(MAX, alpha, beta, alpha);
        }
        b.set(i);
      }
    }
    return score;
  } else {
    int score=WIN;
    int v;
    for(int i=N;i>=0;--i) {
      if (b.test(i)) {
        b.reset(i);
        v=minimax(b,N,alpha,beta,1);
        score=MIN(score,v);
        PRUNE(MIN, alpha, beta, beta);
        if((i-1)>=0 && b.test(i-1)) {
          b.reset(i-1);
          v=minimax(b,N,alpha,beta,1);
          b.set(i-1);
          score=MIN(score,v);
          PRUNE(MIN, alpha, beta, beta);
        }
        if((i+1)<=N && b.test(i+i)) {
          b.reset(i+1);
          v=minimax(b,N,alpha,beta,1);
          b.set(i+1);
          score=MIN(score,v);
          PRUNE(MIN, alpha, beta, beta);
        }
        b.set(i);
      }
    }
    return score;
  }
}

int main(int argc, char **argv) {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T, N;
  std::vector<int> scores;

#ifdef CMDLINE
  if (argc>1) {
    freopen(argv[1], "r", stdin);
  }
#endif
  cin >> T;
  while(T--) {
    cin >> N;
    BitMap board;
    for(int i=N-1;i>=0;i--) {
      cin>>pin;
      if (pin=='I') {
        board.set(i, 1);
      } else {
        board.set(i, 0);
      }
    }
    int s = minimax(board, N-1, LOSE, WIN, 1);
    if (WIN==s) {
      scores.push_back(s);
    } else {
      scores.push_back(LOSE);
    }
  }
  for(int i=0;i<scores.size();++i) {
    printf("%s\n",scores[i]==WIN ? "WIN" : "LOSE");
  }
  return 0;
}
