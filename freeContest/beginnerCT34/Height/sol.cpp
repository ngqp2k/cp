#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		vector<int> l(n), r(n);
		auto sol = [&] (vector<int> a) {
			vector<int> res((int) a.size(), 0);
			stack<int> S;
			for (int i = 0; i < n; ++i) {
				while (!S.empty() && a[S.top()] < a[i])
					S.pop();

				if (!S.empty() && a[S.top()] == a[i]) {
					res[i] = res[S.top()] + 1;
				}
				
				S.push(i);
			}
			return res;
		};

		l = sol(a);
		reverse(a.begin(), a.end());
		r = sol(a);
		reverse(r.begin(), r.end());
		for (int i = 0; i < n; ++i)
			cout << l[i] + r[i] << " ";
		cout << "\n";
  }
}
