/*Author: Vijay Nag
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int N=100006;
typedef unsigned long long ll;
ll A[N+2], st[2*N+1], lazy[2*N+1];
int count;
#define PARENT(i) ((int)(floor((i-1)/2)))

ll buildSegTree_(ll A[], int ss, int se, int idx)
{
   if (ss == se) {
     st[idx] = A[ss] * A[ss];
     return st[idx];
   }

   int mid=(ss + (se-ss)/2);
   st[idx] = buildSegTree_(A, ss, mid, 2*idx+1) +
             buildSegTree_(A, mid+1, se, 2*idx+2);
   return st[idx];
}

void buildSegTree(ll A[], int count)
{
  buildSegTree_(A,0,count-1,0);
}

ll updateSegTree_(ll A[], int idx, int ss, int se, int qs, int qe, int val, int op)
{
  if (qs>qe||qs>se||qe<se) {
    return st[idx]; //no change
  }

  if (ss==se) {
    int diff=op==0?(val*val-st[idx]):(val*val+2*A[PARENT(idx)]*val);
    st[idx]+=diff;
    return st[idx];
  }

  int mid=(ss+(se-ss)/2);
  st[idx] = updateSegTree_(A, 2*idx+1, ss, mid, qs, qe, val, op) +
            updateSegTree_(A, 2*idx+2, mid+1, se, qs, qe, val, op);
  return st[idx];
}

ll updateSegTree(ll A[], int count, int l, int r, int x, int op)
{
    int diff;

    updateSegTree_(A, 0, 0,count-1,l, r, x, op);
    for (int i=l; i<=r;++i) {
      diff = op==0?(x-A[i]):x;
      A[i]+=diff;
    }
}

ll updateSegTreeLazy_(ll A[], int idx, int qs, int qe, int ss, int se, int val, int op)
{
  if (qs>qe||qs>se||qe<se)
    return st[idx]; //no change

  if (lazy[idx]!=0) {
    st[idx] += lazy[idx];
    if (ss!=se) {
      st[2*idx+1] += lazy[idx];
      st[2*idx+2] += lazy[idx];
    }
    lazy[idx]=0;
  }

  if (qs<=ss && qe>=se) {
    int diff=op==0?(val*val-st[idx]):(val*val+2*A[PARENT(idx)]*val);
    st[idx]+=diff;
    if (ss != se) {
      lazy[2*idx+1] += diff;
      lazy[2*idx+2] += diff;
    }
    return st[idx];
  }

  int mid=(ss+(se-ss)/2);
  st[idx] = updateSegTreeLazy_(A, 2*idx+1, qs, qe, ss, mid, val, op) +
            updateSegTreeLazy_(A, 2*idx+1, qs, qe, mid+1, se, val, op);
  return st[idx];
}

void updateSegTreeLazy(ll A[], int count, int l, int r, int x, int op)
{
  updateSegTreeLazy_(A,0,l,r,0,count-1,x,op);
  for (int i=l; i<=r;++i) {
    int diff = op==0?(x-A[i]):x;
    A[i]+=diff;
  }
}

ll querySum_(ll A[], int qs, int qe, int ss, int se, int idx)
{
  if (ss>se || qs > se || qe < ss)
    return 0;

  if (qs<=ss&&qe>=se) {
    return st[idx];
  }

  int mid = (ss+(se-ss)/2);
  return querySum_(A,qs,qe,ss,mid,2*idx+1)+
         querySum_(A,qs,qe,mid+1,se,2*idx+2);
}

ll querySum(ll A[], int count, int l, int r)
{
  return querySum_(A, l, r, 0, count-1, 0);
}

ll querySumLazy_(ll A[], int qs, int qe, int ss, int se, int idx)
{
  if (ss>se || qs > se || qe < ss)
    return 0;

  if (lazy[idx]!=0) {
    st[idx]+=lazy[idx];
    if (ss != se) {
      lazy[2*idx+1]+=lazy[idx];
      lazy[2*idx+2]+=lazy[idx];
    }
    lazy[idx]=0;
  }

  if (qs<=ss&&qe>=se) {
    return st[idx];
  }

  int mid=(ss+(se-ss)/2);
  return querySumLazy_(A, qs, qe, ss, mid, 2*idx+1) +
    querySumLazy_(A, qs, qe, mid+1, ss, 2*idx+2);
}

ll querySumLazy(ll A[], int count, int l, int r)
{
  return querySumLazy_(A, l, r, 0, count-1, 0);
}

int main(int argc, char **argv)
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T, N, Q, CASE=0;

#ifdef CMDLINE
  if (argc>1) {
    freopen(argv[1], "r", stdin);
  }
#endif
  cin >> T;
  while(T--) {
    cin >> N >> Q;
    int count=0;
    while (N--) {
      cin >> A[count++];
    }
    buildSegTree(A, count);
    int opt,st,se,val;
    cout << "Case " << ++CASE << ":" << endl;
    while (Q--) {
      cin>>opt;
      if (2==opt) {
        cin>>st>>se;
        cout<<querySum(A,count,st-1,se-1)<<endl;
      } else {
        cin>>st>>se>>val;
        updateSegTree(A,count,st-1,se-1,val,opt);
      }
    }
  }
  return 0;
}
