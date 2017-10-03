#include <bits/stdc++.h>

using namespace std;

bool comparer(string &lhs, string &rhs)
{
  if (lhs.size() == rhs.size()) {
    return lhs < rhs;
  }
  return lhs.size() < rhs.size();
}

int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }

    sort(unsorted.begin(), unsorted.end(), comparer);
    for (int i=0; i<unsorted.size(); ++i)
        std::cout << unsorted[i] << std::endl;;
    // your code goes here
    return 0;
}
