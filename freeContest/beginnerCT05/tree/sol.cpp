#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define yes "Possible"
#define no "Impossible"
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n);
	for (int &i : a) cin >> i;
	if (a.size() < 2) {
		cout << no;
		return 0;
	}
	else {
		sort(a.rbegin(), a.rend());
		int cnt = 0;
		for(int i: a)
			if (i == a[0])
				cnt++
		if (cnt == )
		if (a[0] != a[1]) {
			cout << no;
			return 0;
		}
		else {
			int maxx = a[0] / 2;
			if (a[0] / 2 == 0) {
				for (int i = 0; i < n; ++i)
					if (a[i] <= maxx) {
						cout << no;
						return 0;
					}
				cout << yes;
			}
			else {
				for (int i = 0; i < n; ++i)
					if (a[i] < maxx) {
						cout << no;
						return 0;
					}
				cout << yes;
			}
		}
	}


}
