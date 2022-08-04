#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector< pair<int, int> > a;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    a.push_back(make_pair(x, i));
  }
  sort(a.begin(), a.end());
  for (auto i: a) 
    cout << i.first << " " << i.second << "\n";
}