#include <bits/stdc++.h>

using namespace std;

vector < int > getRecord(vector < int > s){
    // Complete this function
    vector<int> ans;
    int max_score=0,min_score=0;
    long long maxs=s[0];
    long long mins=s[0];
    
    for(int i=1;i<s.size();++i) {
        if (s[i]>maxs) {
            maxs=s[i];
            max_score++;
        }
        if (s[i]<mins) {
            mins=s[i];
            min_score++;
        }
    }
    ans.push_back(max_score);
    ans.push_back(min_score);
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    string separator = "", delimiter = " ";
    for(auto val: result) {
        cout<<separator<<val;
        separator = delimiter;
    }
    cout<<endl;
    return 0;
}
