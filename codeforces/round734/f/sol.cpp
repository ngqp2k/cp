#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

char letterBlockH[2][2] = {{'a', 'b'}, {'c', 'd'}};
char letterBlockV[2][2] = {{'x', 'y'}, {'z', 't'}};
char letter1H[2] = {'g', 'h'};
char letter1V[2] = {'q', 'p'};
char res[101][101];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, m, kh; cin >> n >> m >> kh;
		int kv = n * m / 2 - kh;
		int X = 0, Y = 0;
		if (n % 2 == 1) {
			if (m % 2 == 1) {
				cout << "NO\n";
				continue;
			}
			kh -= m / 2;
			if (kh < 0) {
				cout << "NO\n";
				continue;
			}
			X++;
			int id = 0;
			for (int i = 1; i <= m; i += 2) {
				res[n][i] = res[n][i + 1] = letter1H[id];
				++id %= 2;
			}
		}
		else if (m % 2 == 1) {
			kv -= n / 2;
			if (kv < 0) {
				cout << "NO\n";
				continue;
			}
			// tao mot hang o ngoai cung ben phai
			Y++;
			int id = 0;
			for (int i = 1; i <= n; i += 2) {
				res[i][m] = res[i + 1][m] = letter1V[id];
				++id %= 2;
			}
		}
		if (kv & 1 || kh & 1) {
			cout << "NO\n";
			continue;
		}

		int id = 0;
		for (int i = 0; i < (n - X) / 2; i++) {
			for (int j = 0; j < (m - Y) / 2; j++) {
				if (kh != 0) {
					res[i * 2 + 1][j * 2 + 1] = res[i * 2 + 1][j * 2 + 2] = letterBlockH[(i + j) % 2][0];
					res[i * 2 + 2][j * 2 + 1] = res[i * 2 + 2][j * 2 + 2] = letterBlockH[(i + j) % 2][1];
					kh -= 2;
				}
				else {
					res[i * 2 + 1][j * 2 + 1] = res[i * 2 + 2][j * 2 + 1] = letterBlockV[(i + j) % 2][0];
					res[i * 2 + 1][j * 2 + 2] = res[i * 2 + 2][j * 2 + 2] = letterBlockV[(i + j) % 2][1];
				}
			}
		}

		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j)
				cout << res[i][j];
			cout << "\n";
		}
	}

	return 0;
}

