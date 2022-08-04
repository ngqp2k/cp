#include <bits/stdc++.h>
using namespace std;

int a[11];
char rooms[11];
vector<int> robots[11];


void solve() {
  vector<int> cnt(11, 0);
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= a[i]; ++j) {
      for (int room : robots[i])
        cnt[room]++;
    }
  }
  for (int i = 1; i <= 9; ++i) {
    if (rooms[i] == 'T') {
      if (cnt[i] % 3 != 0)
        return;
    }
    else if (rooms[i] == 'X') {
      if ((cnt[i] - 2) % 3 != 0)
        return;
    }
    else if (rooms[i] == 'V') {
      if ((cnt[i] - 1) % 3 != 0)
        return;
    }
  }

  int temp[11];
  for(int i = 1; i <= 9; ++i) temp[i] = a[i];

  for(int i = 1; i <= 9; ++i) {
    while(temp[i] != 0) {
      cout << i;
      temp[i]--;
    }
  }
  exit(0);
}

void Try(int i) {
  if (i > 9) {
    print();
  }
  else {
    for (int j = 0; j < 3; ++j) {
      a[i] = j;
      Try(i + 1);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in", "r", stdin);
  // freopen("ou", "w", stdout);
  for (int i = 1; i <= 9; ++i) {
    string s; cin >> s;
    for (char ch : s)
      robots[i].pb((ch - '0'));

  }
  for (int i = 1; i <= 9; ++i)
    cin >> rooms[i];
  Try(1);
  cout << 0;
}