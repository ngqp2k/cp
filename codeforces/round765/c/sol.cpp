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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d(n), a(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    d.push_back(l);
    a.push_back(0);
    const long long inf = (long long) 1e18;
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int p = i - 1; p >= 0; --p) { // 
                debug(i, j, p);
                int old_j = j - (i - p - 1);
                debug(old_j);
                if (old_j >= 0) {
                    dp[i][j] = min(dp[i][j], dp[p][old_j] + (d[i] - d[p])*a[p]);
                }
            }
        }
    }
    cout << *min_element(dp.back().begin(), dp.back().end()) << "\n";
    for (int i = 0; i <= n; ++i)
        debug(dp[i]);
    
    return 0;
}