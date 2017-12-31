#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define N 30009
struct node {
  std::vector<int> A;
};

struct node tree[2*N+10];
int A[N+10];

void build(long long *a, int idx, int l, int r)
{
    if (l==r) {
        tree[idx].A.push_back(a[l]);
        return;
    }

    int mid=(l+(r-l)/2);
    build(a, 2*idx, l, mid);
    build(a, 2*idx+1, mid+1, r);

    tree[idx].A.resize(tree[2*idx].A.size()+tree[2*idx+1].A.size());
    merge(tree[2*idx].A.begin(), tree[2*idx].A.end(),
          tree[2*idx+1].A.begin(),tree[2*idx+1].A.end(), tree[idx].A.begin());
}

long long query(int idx, int qs, int qe, int ss, int se, int k)
{
    if (ss > qe || se < qs || se < ss) { //no overlap
        return 0;
    }

    if (qs <= ss && qe >= se) { //full overlap
        return tree[idx].A.end() - upper_bound(tree[idx].A.begin(), tree[idx].A.end(), k);
    }

    int mid=(ss+(se-ss)/2);
    return query(2*idx, qs, qe, ss, mid, k) + query(2*idx+1, qs, qe, mid+1, se, k);
}


int main()
{
    int c, n, i, j, k, last_ans=0, Q;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    c=1;
    while (c<=n) {
      cin>>A[c++];
    }

    build(A, 1, 1, n);

    cin>>Q;
    while(Q--) {
        cin>>i>>j>>k;
        i^=last_ans;
        j^=last_ans;
        k^=last_ans;
        last_ans=query(1,i,j,1,n,k);
        cout<<last_ans<<endl;
    }
}
