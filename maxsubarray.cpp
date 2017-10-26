/*Author: Vijay Nag
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <limits.h>
using namespace std;

#define MAX(a,b) (a) > (b) ? (a) : (b)
std::vector<long long> a;

void maxSubSum()
{
  long long max_so_far = INT_MIN;
  long long max_ending_here =0;
  long long subseqsum = 0;
  long long max_no=INT_MIN;

  for(int i=0;i<a.size();++i) {
    max_no = max_no < a[i] ? a[i] : max_no;
    subseqsum += a[i] > 0 ? a[i] : 0;
    max_ending_here=MAX(a[i],max_ending_here+a[i]);
    max_so_far=MAX(max_so_far,max_ending_here);
  }

  cout << max_so_far << " " <<(subseqsum==0?max_no:subseqsum)<<std::endl;
}

int main(int argc, char **argv)
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T, N;

#ifdef CMDLINE
  if (argc>1) {
    freopen(argv[1], "r", stdin);
  }
#endif
  cin >> T;
  while(T--) {
    cin >> N;
    a.clear();
    while (N--) {
      long long x;
      cin >> x;
      a.push_back(x);
    }
    maxSubSum();
  }
  return 0;
}
