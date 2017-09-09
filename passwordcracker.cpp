#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX_CHAR 2000
char password[MAX_CHAR];
char login[MAX_CHAR];
std::vector<std::string> opstr;

void matchPassword(std::vector<std::string> &pwords,
        const char *login, std::vector<int> &stridx_vec, int &done)
{
    if (!*login) {
        done = 1;
        return;
    }
    for(int i=0;i<pwords.size()&&!done;++i) {
        if (!strncmp(login, pwords[i].c_str(), strlen(pwords[i].c_str()))) {
            stridx_vec.push_back(i);
            matchPassword(pwords, login+strlen(pwords[i].c_str()), stridx_vec, done);
        }
    }
}

void crackPassword(std::vector<std::string> &pwords,
        const char *login)
{
    std::vector<int> stridx_vec;
    int done = 0;
    matchPassword(pwords, login, stridx_vec, done);
    std::string s;

    if (done && stridx_vec.size()) {
        for(int i =0; i<stridx_vec.size(); ++i) {
            s += pwords[stridx_vec[i]] + " ";
        }
        s+="\n";
    } else {
        s += "WRONG PASSWORD\n";
    }
    opstr.push_back(s);
}

int main()
{
    int T, N;

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
    for(int i=0;i<opstr.size();++i) {
      printf("%s", opstr[i].c_str());
    }
}
