#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << "-> " << #x << ": "; _print(x); cerr << "\n";
template<class T> void _print(T x) { cerr << x;}
template<class T> void _print(vector<T> v) {
    cerr << "[ ";
    for (T val: v) cerr << val << " ";
    cerr << "]";
}

long long tmp = (1LL << 34);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    long long x; cin >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long mxN = 1LL << n;
    dbg(mxN);
    long long ans = 0;
    for (long long mask = 0; mask < mxN; ++mask) {
        long long sum = 0;
        long long cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (long long)(1 << i)) {
                sum += a[i];
                cnt++;
            }
        }
        if (cnt == 0) continue;
        if (sum % cnt == 0)
            if (sum / cnt == x)
                ans++;
        if (mask == tmp) {
            dbg(sum);
            // cout << "sum: " << sum << "\n";
        }
    }
    cout << ans;
    return 0;
}
