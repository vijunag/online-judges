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

#define MAX_CITIES 100000
int visited[MAX_CITIES];
unsigned long long cost;

struct City {
  std::vector<int> neighbors;
};

int dfs(struct City *cities, int node, int n, int lcost, int rcost)
{
  visited[node] = 1;

  for(std::vector<int>::iterator it = cities[node].neighbors.begin();
      it != cities[node].neighbors.end(); ++it) {
    if (!visited[(*it)]) {
      cost += rcost;
      dfs(cities,*it, n, lcost, rcost);
    }
  }
  return 1;
}

int Dfs(struct City *cities, int n, int lcost, int rcost)
{
  for (int i =1; i <= n; ++i) {
    if (!visited[i]) {
      cost += lcost; //new disjoint tree
      dfs(cities, i, n, lcost, rcost);
    }
  }
  return 1;
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        cost = 0;
        int n;
        int m;
        int x;
        int y;
        cin >> n >> m >> x >> y;
        struct City *cities = new City[n+1];
        for (int ii = 1; ii <=n; ++ii)
            visited[ii] = 0;
        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            cities[city_1].neighbors.push_back(city_2);
            cities[city_2].neighbors.push_back(city_1);
        }
        if (y > x) {
          unsigned long long lcost = x;
          lcost *= n;
          printf("%llu\n", lcost);
        } else {
          Dfs(cities,n, x, y);
          printf("%llu\n", cost);
        }
        delete []cities;
    }
    return 0;
}
