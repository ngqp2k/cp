#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
	long long res = 0;
  int right = -1, sum = 0;
  for (int i = 0; i < n; ++i) {
    while (sum <= t && right < n) {
			sum += a[++right];
    }
		res += right - i;
		sum -= a[i];
  }
	cout << res;
  return 0;
}
