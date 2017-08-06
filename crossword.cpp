#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <ctype.h>
using namespace std;

#define MAX_ROW 10
#define MAX_COL 10

char grid[MAX_ROW][MAX_COL];
char wordList[100];
char *wordArray[MAX_ROW+1];
int visited[100];
int wcount = 0;

void UnFillwords(int r, int c, int row_wise, int cnt)
{
    while (cnt--) {
        if (row_wise) {
            if (r > 0 && isalpha(grid[r-1][c])) {
                c++;
                continue;
            }
            if (r < 9 && isalpha(grid[r+1][c])) {
                c++;
                continue;
            }
            grid[r][c++] = '-';
        } else {
            if ( c > 0 && isalpha(grid[r][c-1])) {
                r++;
                continue;
            }
            if ( c<9 && isalpha(grid[r][c+1])) {
                r++;
                continue;
            }
            grid[r++][c] = '-';
        }
    }
}

void Fillwords(const char *s, int r, int c,
        int row_wise, int cnt)
{
   int i=0, row=r, col=c;

   while (i < cnt) {
       if ((grid[row][col] !='-') && (s[i]!=grid[row][col])) {
           return; //backtrack
       }
       if (row_wise)
           col++;
       else
           row++;
       i++;
   }

   i=0;
   while(cnt) {
       if (row_wise) {
           grid[r][c++] = s[i++];
       } else {
           grid[r++][c] = s[i++];
       }
     cnt--;
   }
}

void FindPossibleWords(std::vector<std::pair<int, char*> > &svec, int cnt)
{
    for(int i=0;i<wcount;++i) {
        if(!visited[i] && (cnt==strlen(wordArray[i]))) {
            svec.push_back(std::pair<int, char*>(i, wordArray[i]));
        }
    }
}

void NextGrid(int &row, int &col, int &row_wise, int &cnt)
{
    int i=0,j=0;
    row_wise = 0;
    for (i=0; i<MAX_ROW;++i) {
        for (j=0;j<MAX_COL;++j) {
            if (grid[i][j] != '+') {
                if (j<9&&grid[i][j+1]=='-') {
                    row_wise=1;
                    goto loop2;
                } else if (i<9&&grid[i+1][j]=='-') {
                    goto loop2;
                }
            }
        }
    }

loop2:
    row=i;
    col=j;
    while(i<=9 && j<=9) {
        if (row_wise) {
            if (grid[i][j++]=='+') {
                break;
            }
        } else {
            if (grid[i++][j]=='+') {
                break;
            }
        }
        cnt++;
    }
}

void PrintGrids(void)
{
    for(int i=0; i<MAX_ROW;++i) {
        for(int j=0;j<MAX_COL;j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void solve()
{
    std::vector<std::pair<int, char*> > svec;
    int row, col, row_wise, cnt=0;
    NextGrid(row, col, row_wise, cnt);

    if (!cnt) //we have a solution
        PrintGrids();

    FindPossibleWords(svec, cnt);
    for(int i=0; i<svec.size(); ++i) {
        Fillwords(svec[i].second, row, col, row_wise, cnt);
        visited[svec[i].first] = 1;
        solve();
        UnFillwords(row, col, row_wise, cnt);
        visited[svec[i].first] = 0;
    }
}

int main() {
    char *temp = &wordList[0], *ptr;

    for (int i = 0; i < 10; i++) {
        char dummy;
        for (int j = 0; j < 10; ++j) {
            scanf("%c", &grid[i][j]);
        }
        scanf("%c", &dummy);
    }
    scanf("%s", &wordList[0]);
    while (ptr=strtok_r(temp, ";", &temp)) {
        char *w = (char*)malloc(strlen(ptr));
        strncpy(w, ptr, strlen(ptr));
        wordArray[wcount++] = w;
    }
    solve();
    return 0;
}
