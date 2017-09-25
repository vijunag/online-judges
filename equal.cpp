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
#include <limits.h>

using namespace std;

#define MAX(a,b) (a) > (b) ? (a) : (b)
#define MIN(a,b) (a) < (b) ? (a) : (b)

long GetMin(std::vector<long> &l, int min)
{
    long min_count = LONG_MAX;
    long count = 0;

    for(int i=0; i<3; ++i) {
        count = 0;
        for (int j = 0; j < l.size(); ++j) {
          long diff = 0;
          long m = min-i; 
          diff = l[j] - m;
          count += diff/5 + (diff%5)/2 + ((diff%5)%2)/1;
        }
        min_count = MIN(min_count, count);
    }
    return min_count;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long T, N;
    cin >> T;

    long min = LONG_MAX;

    while(T--) {
        std::vector<long> l;
        min = LONG_MAX;
        cin >> N;
        while (N--) {
            long n;
            cin >> n;
            l.push_back(n);
            min=MIN(min,n);
        }
        cout << GetMin(l, min) << std::endl;
    }
    return 0;
}
