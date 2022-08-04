#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	int a, b; cin >> a >> b;	
	bool B[19];
	memset(B, false, sizeof B);
	B[0] = B[3] = B[6] = B[9] = B[11] = B[14] = B[17] = true;

	int cnt = 0;
	for(int i = a; i <= b; ++i)
		if (B[i % 19])
			cnt++;
	cout << cnt;
	return 0;
}
