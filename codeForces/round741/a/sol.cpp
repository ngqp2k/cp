#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    int left, right; cin >> left >> right;
    if (left <= (right / 2) + 1)
      cout << right - (right / 2) - 1 << "\n";
    else
      cout << right % left << "\n";
  }
}