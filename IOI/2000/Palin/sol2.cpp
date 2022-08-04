#include <bits/stdc++.h>
using namespace std;

#define mxN 5001

void print(vector<int> a) {
  for (int i : a)
    cout << i << " ";
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<char> ch(n);
  for (int i = 0; i < n; ++i)
    cin >> ch[i];

  vector< vector<int> > f(2);
  for (int i = 0; i < n; ++i) f[0].push_back(0);
  for (int i = 0; i < n - 1; ++i)
    if (ch[i] == ch[i + 1]) f[1].push_back(0);
    else f[1].push_back(1);

  // cout << "F[0]: "; print(f[0]); cout << "\n";
  // cout << "F[1]: "; print(f[1]); cout << "\n\n";

  for (int t = 2; t < n; ++t) {
    vector<int> temp;
    for (int i = 0; i < n - t; ++i) {
      int j = i + t;
      if (ch[i] == ch[j])
        temp.push_back(f[0][i + 1]);
      else {
        int x = min(f[1][i], f[1][i + 1]) + 1;
        temp.push_back(x);
      }
    }
    f[0] = f[1];
    f[1] = temp;
    // cout << "F[0]: "; print(f[0]); cout << "\n";
    // cout << "F[1]: "; print(f[1]); cout << "\n\n";
  }
  cout << f[1][0];
}