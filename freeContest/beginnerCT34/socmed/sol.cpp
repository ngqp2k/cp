#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<string> a;
	map<string, pair<string, int>> m;
	for (int i = 0; i < n; ++i) {
		string s1, s2; cin >> s1 >> s2;
		a.push_back(s1);
		m[s1].first = s2;
		m[s1].second = 0;
	}
	int k; cin >> k;
	for (int i = 0; i < k; ++i) {
		string s1, s2; cin >> s1 >> s2;
		if (s2 == m[s1].first)
			m[s1].second ++;
	}
	for (int i = 0; i < n; ++i)
		cout << m[a[i]].second << " ";
}

