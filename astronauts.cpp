#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

#define MAX_ASTROS 100000
char visited[100000];
using namespace std; // }}}

int dfs(int i, vector<vector <int> > &edges, long long &level)
{
    visited[i] = 1;
    for (int j = 0; j < edges[i].size(); ++j) {
        if (!visited[edges[i][j]]) {
            level++;
            dfs(edges[i][j], edges, level);
        }
    }
    return 1;
}

long long Dfs(vector< vector <int> >& pairs)
{
    long long ans = 0, sum=0;

    for (int i = 0; i < pairs.size(); ++i) {
        long long count = 1;
        if (!visited[i]) {
            dfs(i, pairs, count);
            ans += sum * count;
            sum += count;
        }
    }
    return ans;
}

int main()
{
    int N, I;
    //freopen("input", "r", stdin);
    cin >> N >> I;
    vector<vector<int> > pairs(N);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }

    /** Write code to compute the result using N, I, pairs **/
    long long result = Dfs(pairs);
    cout << result << endl;
    return 0;
}
