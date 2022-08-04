#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const long long INFLL = (long long)1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

void solve(){
	long long k; cin >> k;
	// 1 <= m <= n
	// n - m nho nhat
	// 2nm + n + m = 2k - 1
	// m(2n + 1) = 2k - 1 - n
	int i = -1, j = -1;
	long long Min = INFLL;
	for(int n = 1; n <= (int) sqrt(2 * k); ++n) {
		if (((2 * k - 1) - n) % (2 * n + 1) == 0) {
			int m = ((2 * k - 1) - n) / (2 * n + 1);
			if (max(n, m) - min(n, m) < Min){
				i = min(n, m), j = max(n, m);
				Min = j - i;
			}
		}
	}
	if (i == 0 || (i == -1 && j == -1))
		cout << -1;
	else cout << i << " " << j;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	int tt = 1; 
	//cin >> tt;
	while(tt--) {
		solve();
	}
	return 0;
}
