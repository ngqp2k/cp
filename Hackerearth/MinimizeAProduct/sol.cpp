#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
const int MOD = 1e9 + 7;

struct Node {
  int fiMin, seMin, cntFi, cntSe;
  void isLeaf(int val) {
    fiMin = val, cntFi = 1, seMin = INF, cntSe = 0;
  }
  void isINF() {
    fiMin = seMin = INF;
    cntFi = cntSe = 0;
  }
  void unify(Node a, Node b) {
    fiMin = min(a.fiMin, b.fiMin);
    seMin = min(a.seMin, b.seMin);
    cntFi = cntSe = 0;
    if (fiMin == a.fiMin)
      cntFi += a.cntFi;
    else
      seMin = min(seMin, a.fiMin);

    if (fiMin == b.fiMin)
      cntFi += b.cntFi;
    else
      seMin = min(seMin, b.fiMin);

    if (seMin == a.fiMin) cntSe += a.cntFi;
    if (seMin == a.seMin) cntSe += a.cntSe;
    if (seMin == b.fiMin) cntSe += b.cntFi;
    if (seMin == b.seMin) cntSe += b.cntSe;
  }
};

struct ST {
  int n;
  vector<int> a;
  vector<Node> st;
  ST (vector<int> v): n(v.size()), a(v), st(n * 4) {
    build(1, 0, n - 1);
  };
  void build(int node, int left, int right) {
    // cout << node << " " << left << " " << right << "\n";
    if (left == right) {
      st[node].isLeaf(a[left]);
      return;
    }
    int mid = (left + right) / 2;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
    st[node].unify(st[node * 2], st[node * 2 + 1]);
  }
  void update(int node, int left, int right, int id, int val) {
    if (left == right) {
      st[node].isLeaf(val);
      return;
    }
    int mid = (left + right) / 2;
    if (id <= mid)
      update(node * 2, left, mid, id, val);
    else
      update(node * 2 + 1, mid + 1, right, id, val);
    st[node].unify(st[node * 2], st[node * 2 + 1]);
  }

  void update(int id, int val) { update(1, 0, n - 1, id - 1, val); }

  Node query(int node, int left, int right, int l, int r) {
    if (left > r || right < l) {
      Node res; res.isINF();
      return res;
    }
    if (l <= left && right <= r)
      return st[node];
    int mid = (left + right) / 2;
    Node res;
    res.unify(query(node * 2, left, mid, l, r), query(node * 2 + 1, mid + 1, right, l, r));
    return res;
  }

  Node query(int l, int r) { return query(1, 0, n - 1, l - 1, r - 1); }
};

void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  ST st(a);


  int ans = 0;
  while (q--) {
    int c; cin >> c;
    if (c == 1) {
      int id, val; cin >> id >> val;
      st.update(id, val);
    }
    else {
      int l, r; cin >> l >> r;
      Node res = st.query(l, r);
      if (res.cntFi == 1)
        ans += res.cntSe % MOD;
      else
        ans += (res.cntFi * (res.cntFi - 1) / 2) % MOD;
    }
  }
  cout << ans % MOD << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    solve();
  }
}
