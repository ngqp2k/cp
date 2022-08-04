#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int mxN = 1e6 + 11;

string s;

struct Node {
	int close, open, res;
	Node() {}
	Node (int a, int b, int c) {
		res = a;
		open = b;
		close = c;
	};
	void unify(Node a, Node b) {
		int tmp = min(a.open, b.close);
		res = a.res + b.res + tmp * 2;
		open = a.open + b.open - tmp;
		close = a.close + b.close - tmp;
	}
};

Node st[mxN * 4];

void build(int p, int left, int right) {
	if (left == right) {
		if (s[left] == '(')
			st[p] = Node(0, 1, 0);
		else
			st[p] = Node(0, 0, 1);
		return;
	}
	int mid = (left + right) / 2;
	build(p * 2, left, mid);
	build(p * 2 + 1, mid + 1, right);
	st[p].unify(st[p * 2], st[p * 2 + 1]);
}

Node get(int p, int left, int right, int l, int r) {
	if (left > r || right < l)
		return Node(0, 0, 0);
	if (l <= left && right <= r)
		return st[p];
	int mid = (left + right) / 2;
	Node res;
	res.unify(get(p * 2, left, mid, l, r), get(p * 2 + 1, mid + 1, right, l, r));
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	// freopen("input.inp", "r",stdin);
	cin >> s;
	int n = s.size();
	build(1, 0, n - 1);

	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		--l, --r;
		cout << get(1, 0, n - 1, l, r).res << "\n";
	}
}
