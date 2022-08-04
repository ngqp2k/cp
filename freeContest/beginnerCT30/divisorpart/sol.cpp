#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define FO(x) {freopen("in"#x,"r",stdin);freopen("ou"#x,"w",stdout);}

using namespace std;
const int N = 1e6 + 1;
const int LOG = 20;
const int MOD = 1e9 + 7 ;
const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> II;

int n, q;
int a[N], f[N], st[4 * N];


void buildST(int node, int left, int right) {
	if (left == right) {
		st[node] = f[right];
		return;
	}
	int mid = (left + right) / 2;
	buildST(node * 2, left, mid);
	buildST(node * 2 + 1, mid + 1, right);
	st[node] = max(st[node * 2], st[node * 2 + 1]);
}

void updateST(int node, int left, int right, int index, int val) {
	if (index < left || index > right)
		return;
	if (left == right) {
		st[node] = val;
		return;
	}
	int mid = (left + right) / 2;
	updateST(node * 2, left, mid, index, val);
	updateST(node * 2 + 1, mid + 1, right, index, val);
	st[node] = max(st[node * 2], st[node * 2 + 1]);
}

int getMax(int node, int left, int right, int u, int v) {
	if (left > v || right < u)
		return -1;
	if (u <= left && right <= v)
		return st[node];
	int mid = (left + right) / 2;
	return max(getMax(node * 2, left, mid, u , v), getMax(node * 2 + 1, mid + 1, right, u, v));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// FO(1);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i == 1)
			f[1] = 1;
		else {
			f[i] = (a[i] % a[i - 1] == 0) ? 0 : i;
		}
	}
	buildST(1, 1, n);
	a[n + 1] = 1;
	while (q--) {
		int chose; cin >> chose;
		if (chose == 1) {
			int index, val; cin >> index >> val;
			a[index] = val;

			if (index == 1) continue;

			if (index < n)
				if (a[index + 1] % val == 0) // f[index + 1] = 0
					updateST(1, 1, n, index + 1, 0);
				else
					updateST(1, 1, n, index + 1, index + 1);
			else;

			if (val % a[index - 1] == 0) // f[index] = 0;
				updateST(1, 1, n, index, 0);
			else
				updateST(1, 1, n, index, index);
		}
		else {
			int index; cin >> index;
			cout << getMax(1, 1, n, 1, index) << "\n";
		}
	}
	return 0;
}