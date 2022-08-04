#include <bits/stdc++.h>
 
using namespace std;
 
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int mxN = (int) 1e5 + 11;

int n, m;
vector<int> g[mxN];

int low[mxN], num[mxN], tail[mxN], parent[mxN];
int timeDfs = 0, root, child;

bool isCut[mxN];
vector<pair<int, int>> bridges;

void dfs(int u) {
    num[u] = low[u] = ++timeDfs;
    for (int v: g[u]) {
        if (v == parent[u])
            continue;
        if (!num[v]) {
            if (u == root)
                child++;
            parent[v] = u;
            dfs(v);
            if (low[v] == num[v]) {
                bridges.push_back(make_pair(u, v));
            }
            if (low[v] >= num[u] && u != root) {
                isCut[u] = true;
            }
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }
    tail[u] = timeDfs;
}

bool isVInU(int v, int u) {
    if (num[u] <= num[v] && num[v] <= tail[u])
        return true;
    return false;
}

void solve1(int a, int b, int g1, int g2) {
    if (num[g1] < num[g2])
        swap(g1, g2);
    // g1 la con cua g2
    if (low[g1] == num[g2]) {
        bool b1 = isVInU(a, g1);
        bool b2 = isVInU(b, g1);
        if (b1 && b2 || !b1 && !b2)
            cout << "true\n";
        else
            cout << "false\n";
    }
    else
        cout << "false\n";
}

void solve2(int a, b, c) {
    ;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(num, 0, sizeof(num));
    memset(isCut, false, sizeof(isCut));

    for (int i = 1; i <= n; ++i) {
        if (!num[i]) {
            root = i, child = 0;
            dfs(i);
            isCut[i] = (child > 1);
        }
    }

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int a, b, g1, g2; cin >> a >> b >> g1 >> g2;
            solve1(a, b, g1, g2);
        }
        else {
            int a, b, c; cin >> a >> b >> c;
            solve2(a, b, c);
        }
    }

    // cout << "Bridges: "; 
    // for (auto p: bridges)
    //     cout << "(" << p.first << ", " << p.second << "), ";

    // cout << "\nCut: ";
    // for (int i = 1; i <= n; ++i)
    //     if (isCut[i])
    //         cout << i << ", ";

    return 0;
}