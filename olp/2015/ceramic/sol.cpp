#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a, vector<int> b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < (int) a.size(); ++i)
		if (a[i] != b[i])
			return false;
	return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
		
	vector<pair<int, pair<int, int>>> res;
	for (int step = 1; step <= (n / 2); ++step) 
		if (n % step == 0) {
			vector<int> va, vb;
			int res_a = 0, res_b = 0;
			bool ok = true;
			for (int i = 0; i < n - step + 1; i += step) {
				vector<int> t;
				for (int j = i; j < i + step; ++j)
					t.push_back(a[j]);

				if (va.empty()) {
					va = t;
					res_a++;
				}
				else if (check(va, t))
					res_a++;
				else if (vb.empty()) {
					vb = t;
					res_b++;
				}
				else if (check(vb, t))
					res_b++;
				else { // break; 
					ok = false;
					break;
				}
			}
			if (va.empty() || vb.empty())
				ok = false;
			if (ok)
				res.push_back(make_pair(step, make_pair(res_a, res_b)));
		}
		if (res.empty())
			cout << -1;
		else {
			cout << res.size() << "\n";
			for (auto i: res) {
				cout << i.first << " ";
				cout << max(i.second.first, i.second.second) << " ";
				cout << min(i.second.first, i.second.second) << "\n";
			}
		}
}
