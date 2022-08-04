#include<bits/stdc++.h>
using namespace std;

struct myCtr {
	int pos, deg;
};
myCtr d[1000 + 10];

int n;
int a[1010][1010];

bool cmp(myCtr d1, myCtr d2) { return d1.deg < d2.deg; }

void init() {
	for(int i = 1; i <= 1010; ++i) {
		d[i].pos = i;
		d[i].deg = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	init();
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 1)
				d[i].deg++;
		}
	sort(d + 1, d + n + 1, cmp);
	for(int i = 1; i <= n - 1; ++i)
		if (d[i].deg == d[i + 1].deg) {
			int u = d[i].pos;
			int v = d[i + 1].pos;
			for(int j = 1; j <= n; ++j)
				if (a[u][v]) {
					if (a[v][j] == 1 && a[j][u] == 1) {
						cout << u << " " << v << " " << j;
						return 0;
					}
				}
				else {
					if (a[u][j] == 1 && a[j][v] == 1) {
						cout << v << " " << u << " " << j;
						return 0;
					}
				}

		}
	cout << "-1 -1 -1";
}
