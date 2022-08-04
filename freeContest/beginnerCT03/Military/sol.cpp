#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
	int n, a, b;
	cin >> n >> a >> b; 
	if (a > b || n < 1)
		cout << 0 << endl;
	else if (n == 1) 
		cout << (a == b ? 1 : 0) << endl;
	else { 
		int res = (b - a) * (n - 2) + 1;
		cout << res;
	}

	return 0;
}