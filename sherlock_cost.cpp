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

using namespace std;

#define max(a,b) (a) > (b) ? (a) : (b)

long MaximizeDiff(std::vector<long> &b)
{
    std::vector<long> with(b.size()), without(b.size());
    
    for(int i=1;i<b.size();++i) {
        with[i] = max(with[i-1], b[i]-1 + without[i-1]);
        without[i] = max(without[i-1], b[i-1]-1+with[i-1]);
    }
    return max(without[b.size()-1], with[b.size()-1]);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long T, N;
    
    cin >> T;
    while (T--) {
        cin >> N;
        std::vector<long> l;
        while (N--) {
            long num;
            cin >> num;
            l.push_back(num);
        }
        cout << MaximizeDiff(l) << std::endl;
    }
    return 0;
}
