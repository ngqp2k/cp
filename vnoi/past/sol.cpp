#include <iostream>
#define int long long
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, res = 1;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		res += i;
	cout << res;
}