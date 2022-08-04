#include<bits/stdc++.h>
#define int long long

using namespace std;

int const mxN = 1e5 + 10;

int ft[mxN];
int N, Q;

void update(int index, int val) {
	int i = index;
	while (i <= N) {
		ft[i] += val;
		i += i & (-i);
	}
}

int getSum(int v) {
	int sum = 0;
	while(v > 0) {
		sum += ft[v];
		v -= (v & (-v));
	}
	return sum;
}

int32_t main() {
	cin >> N >> Q;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		update(i + 1, a[i]);
	}

	while (Q--) {
		int chose, u , v; cin >> chose >> u >> v;
		if (chose == 1) {
			update(u, v);
		}
		else
			cout << getSum(v) - getSum(u - 1) << "\n";
	}

	return 0;
}
