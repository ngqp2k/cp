#include <bits/stdc++.h>
using namespace std;

long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rand() * 1LL * rand() % (h - l + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  srand(time(NULL));
  freopen("in1", "w", stdout);
  int n = 100;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
    a[i] = Rand(-1000, 1000);
  for (int j = 0; j < n; ++j)
    b[j] = Rand(1, 2);

  cout << n << "\n";
  for (int i: a)
    cout << i << " ";
  cout << "\n";
  for (int i: b)
    cout << i << " ";
}
