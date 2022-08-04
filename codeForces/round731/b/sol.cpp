#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.length();
  vector<int> pos(50, -1);
  int pos_a = -1;
  for (int i = 0; i < n; ++i)
    if (s[i] == 'a') {
      pos_a = i;
      break;
    }

  if (pos_a == -1) {
    cout << "NO\n";
    return;
  }

  int curLeft = pos_a;
  int curRight = pos_a;

  int cnt = 1;
  int i = 1;
  while (cnt < n) {
    char c = char(i + 97);
    if (c == s[max(0, curLeft - 1)]) {
      curLeft--;
    }
    else if (c == s[min(curRight + 1, n - 1)]) {
      curRight++;
    }
    else {
      cout << "NO\n";
      return;
    }
    i++, cnt++;
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    solve();
  }
}