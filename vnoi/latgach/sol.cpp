#include <bits/stdc++.h>
#define infi 1e9
#define infll 1e18
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)

string add(string s1, string s2) {
    if (s1.length() < s2.length())
        swap(s1, s2);
    while (s2.length() < s1.length())
        s2 = "0" + s2;

    string ans = "";
    int tmp = 0;
    for (int i = s1.length() - 1; i >= 0; --i) {
        int x = (s1[i] - '0');
        int y = (s2[i] - '0');
        int sum = x + y + tmp;
        tmp = sum / 10;
        sum = sum % 10;
        ans = to_string(sum) + ans;
    }
    if (tmp)
        ans = "1" + ans;
    return ans;
}

string f[110];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    f[1] = "1", f[2] = "2", f[3] = "3";
    for (int i = 4; i <= 100; ++i)
        f[i] = add(f[i - 1], f[i - 2]);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        cout << f[n] << '\n';
    }

    return 0;
}