#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string.h>
using namespace std;

int getID(int a, int x) {
	return a * 8 + (8 - (x + 1));
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//ifstream fi("stone.inp");
	//ofstream fo("stone.out");
	int m, n, k;
	cin >> m >> n >> k;
	vector<int> a;
	for (int i = 0; i < m; ++i) {
		int x; cin >> x;
		for (int j = 7; j >= 0; --j) {
			a.push_back((x & (1 << j)) != 0);
		}
	}

	vector<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int left = getID(x1, y1), right = getID(x2, y2);
		// cout << left << " " << right << "\n";
		q.push_back(make_pair(left, right));
	}
	sort(q.begin(), q.end(), cmp);

	int curLeft = q[0].first, curRight = q[0].second;

	for (int i = curLeft; i <= curRight; ++i) a[i] = 0;

	for (int i = 1; i < n; ++i) {
		if (q[i].second <= curRight) continue;
		if (q[i].first >= curRight) {
			for (int j = q[i].first; j <= q[i].second; ++j)
				a[j] = 0;
			curLeft = q[i].first, curRight = q[i].second;
		}
		else if (q[i].first < curRight) {
			for (int j = curRight; j <= q[i].second; ++j)
				a[j] = 0;
			curLeft = curRight, curRight = q[i].second;
		}
	}

	vector<int> f((int)a.size());
	for (int i = 0; i < (int)a.size(); ++i) {
		if (i == 0)
			f[i] = a[i];
		else f[i] = f[i - 1] + a[i];
	}

	for (int i = 0; i < k; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int left = getID(x1, y1), right = getID(x2, y2);

		if (left == 0) {
			if (f[right] != 0)
				cout << "YES\n";
			else
				cout << "PASS\n";
		}
		else if (f[right] != f[left - 1])
			cout << "YES\n";
		else
			cout << "PASS\n";
	}

	//for (int i: a) cout << i << " ";
	//fi.close();
	//fo.close();
	return 0;
}
