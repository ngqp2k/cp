#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 11;
bool ok[mxN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  //1 4 9 16 25 36 49 64 81
  int n, m;
  cin >> n >> m;
  memset(ok, false, sizeof(ok));
  for (int i = 1; i * i <= n; ++i)
    ok[i * i] = true;
}