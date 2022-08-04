#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

bool cmp(int a, int b) {return a > b;}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector< vector<int> > f(5);
		int ans = 0;
		for (int i = 0; i < n ; ++i) {
			string s; cin >> s;
			int size = s.length();
			vector<int> cnt(5, -size);
			for (char c : s) {
				if (cnt[c - 'a'] == -size)
					cnt[c - 'a'] = 0;
				cnt[c - 'a']++;
			}
			for (int j = 0; j < 5; ++j) {
				if (cnt[j] != -size)
					f[j].pb(cnt[j] * 2 - size);
				else
					f[j].pb(-size);
			}
		}
		for (int i = 0; i < 5; ++i) {
			sort(f[i].begin(), f[i].end(), cmp);
			int curWord = 0, sum = 0;
			for (int v : f[i])
				if (sum + v <= 0)
					break;
				else { sum += v; curWord++; }
			ans = max(ans, curWord);
		}
		cout << ans << "\n";
	}
	return 0;
}

