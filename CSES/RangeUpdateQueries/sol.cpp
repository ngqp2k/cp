#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 2e5 + 10; 

int f[mxN];
int N, Q;

void update(int index, int val) {
	int i = index;
	while (i <= N) {
		f[i] += val;
		i += i & -i;
	}
}

int getSum(int u) {
	int i = u, sum = 0;
	while (i > 0) {
		sum += f[i];
		i -= i & -i;
	}
	return sum;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> Q;
	int x; cin >> x;
	update(1, x);
	for(int i = 2; i <= N; ++i) {
		int temp = x; cin >> x;
		update(i, x - temp);
	}

	while (Q--) {
		int c; cin >> c;
		if (c == 1) {
			int l, r, val; cin >> l >> r >> val;
			update(l, val); update(r + 1, -val);
		}
		else {
			int k; cin >> k;
			cout << getSum(k) << "\n";
		}
	}
	return 0;
}

