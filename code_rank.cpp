#include <iostream>
#include <map>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define min(a, b) (a) < (b) ? (a) : (b)

struct comparer {
    bool operator()(const std::pair<int, int> &lhs,
	            const std::pair<int, int> &rhs) const
    {
	if ((lhs.first == rhs.first) && (lhs.second == rhs.second))
	    return false;

	return (lhs.first <= rhs.first && lhs.second <= rhs.second);
    }
};

typedef std::map<std::pair<int,int>,int, comparer> rankMap;
typedef std::map<int, int> intMap;
int main()
{
  rankMap map;
  intMap rmap;
  int count;

  scanf("%d", &count);
  for(unsigned int i =0; i < count; ++i) {
     int ith, jth;
     scanf("%d %d", &ith, &jth);
     map[std::pair<int, int>(ith, jth)] = i;
  }

  int maxi = 0;
  for (rankMap::iterator it = map.begin();
      it != map.end(); ++it) {
      rmap[it->second] =  maxi++;
  }

  for(unsigned int i = 0; i < count; ++i) {
     printf("%d\n", rmap[i]);
  }

  return 0;
}
