// BIT
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 1e5 + 10; 
int bit1[mxN], bit2[mxN], diff[mxN], a[mxN];
int N, Q;

void updatePoint(int f[], int index, int val) {
	int i = index;
	while (i <= N) {
		f[i] += val;
		i += i & (-i);
	}
}

void updateRange(int l, int r, int val) {
	updatePoint(bit1, l, (N - l + 1) * val);
	updatePoint(bit1, r + 1, -(N - r) * val);
	updatePoint(bit2, l, val);
	updatePoint(bit2, r + 1, -val);
}


int getSum(int f[], int u) {
	int i = u, sum = 0;
	while (i > 0) {
		sum += f[i];
		i -= i & (-i);
	}
	return sum;
}

// get sum from 1 -> u
int getSumOnBIT(int u) {
	return getSum(bit1, u) - (N - u) * getSum(bit2, u);
}

int getSumOnRange(int l, int r) {
	return getSumOnBIT(r) - getSumOnBIT(l - 1);
}

void test(vector<int> f);

void solve() {
	;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> Q;
	for(int i = 1; i <= N; ++i) {
		cin >> a[i];
		if (i == 1)
			diff[i] = a[i];
		else
			diff[i] = a[i] - a[i - 1]; 
		updatePoint(bit1, i, (N - i + 1) * diff[i]);
		updatePoint(bit2, i, diff[i]);
	}

	while (Q--) {
		int c, l, r; cin >> c >> l >> r;
		if (c == 1) {
			int val; cin >> val;
			updateRange(l, r, val);
		}
		else {
			cout << getSumOnRange(l, r) << "\n";
		}
	}

	return 0;
}
