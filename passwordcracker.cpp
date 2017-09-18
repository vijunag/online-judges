#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;

#define MAX_CHAR 2000
char password[MAX_CHAR];
char login[MAX_CHAR];
#ifdef XXX
std::vector<std::string> opstr;
#endif
std::set<std::string> matched;

int matchPassword(std::vector<std::string> &pwords,
        const char *login, std::vector<int> &stridx_vec, int &done)
{
  if (!*login) {
    done = 1;
    return 1; //login string has been reduced
  }

  if (matched.find(login) != matched.end()) {
    return 0;
  }

  for(int i=0; i<pwords.size()&&!done; ++i) {
    if (!strncmp(login, pwords[i].c_str(), pwords[i].size())) {
      stridx_vec.push_back(i);
      if (matchPassword(pwords, login+pwords[i].size(), stridx_vec, done)) {
      } else {
        stridx_vec.pop_back();
        matched.insert(login);
      }
    }
  }
  return done;
}

void crackPassword(std::vector<std::string> &pwords,
        const char *login)
{
    std::vector<int> stridx_vec;
    int done = 0;
    matchPassword(pwords, login, stridx_vec, done);
    std::string s;

    matched.clear();
    if (done && stridx_vec.size()) {
        for(int i =0; i<stridx_vec.size(); ++i) {
            printf("%s ", pwords[stridx_vec[i]].c_str());
        }
        printf("\n");
    } else {
        printf("WRONG PASSWORD\n");
    }
}

int main(int argc, char **argv)
{
    int T, N;

#ifdef CMDLINE
    freopen(argv[1], "r", stdin);
#endif /*CMDLINE*/
    scanf("%d", &T);

    while (T--) {
        std::vector<std::string> pwords;
        scanf("%d", &N);
        while(N--) {
            scanf("%s", password);
            pwords.push_back(password);
        }
        scanf("%s", login);
        crackPassword(pwords, login);
    }
#ifdef XXX
    for(int i=0;i<opstr.size();++i) {
      printf("%s", opstr[i].c_str());
    }
#endif /*XXX*/
}
