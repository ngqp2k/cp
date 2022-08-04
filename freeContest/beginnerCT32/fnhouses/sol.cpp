#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 1e3 + 10; 

int m, n;
int a[N][N];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> m >> n;

	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j) {
			char ch; cin >> ch;
			if (ch == '#') a[i][j] = 1;
			else a[i][j] = 0;
		}

	int maxAdj = 0, cnt = 0;

	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j) {
			if (a[i][j] == 0) {
				int s = 0;
				for(int ii = 0; ii < 8; ++ii)
					s += a[i + dx[ii]][j + dy[ii]];
				maxAdj = max(maxAdj, s);
			}
			else {
				for(int ii = 0; ii < 8; ++ii)
					cnt += a[i + dx[ii]][j + dy[ii]];
			}
		}

	cout << cnt / 2 + maxAdj;

	return 0;
}

