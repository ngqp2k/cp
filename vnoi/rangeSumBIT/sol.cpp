#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
// #define int long long
using namespace std;

const int mxN = 1e5 + 10; 

vector<int> bit1, bit2;

void updatePoint(vector<int> &f, int index, int val) {
	int i = index;
	while(i <= f.size()) {
		f[i] += val;
		i += i & (-i);
	}
}

void updateRange(int l, int r, int val) {
	updatePoint(bit1, l, (n - l + 1) * v);
	updatePoint(bit1, r + 1, - (n - r) * v);
	updatePoint(bit2, l, v);
	updatePoint(bit2, r + 1, -v);
}

int getSumOnBit(vector<int> &b, int u) {
	tinhr;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n + 1, 0), s1(n + 1, 0), s2(n + 1, 0);
	bit1.resize(n + 1, 0), bit2.resize(n + 1, 0);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		update(bit2, i, a[i]);
	}
	return 0;
}

