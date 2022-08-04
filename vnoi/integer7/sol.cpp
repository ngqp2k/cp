#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 1e5 + 10; 

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;
	int x1 = 0, x2 = 1e18;

	while(1) {
		x1++;
		if ((a1 * x1 + b1 - b2) % a2 == 0)
			x2 = (a1 * x1 + b1 - b2) / a2;
		if (x1 > x2)
			break;
	}

	cout << x1 << " " << x2; 
	return 0;
}
