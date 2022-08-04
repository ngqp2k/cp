#include <bits/stdc++.h>
using namespace std;

string to_string(const string &s)
{
    return '"' + s + '"';
}

string to_string(bool b)
{
    return (b ? "True" : "False");
}

template <typename A>
string to_string(A v)
{
    string res = "{";
    bool first = true;
    for (const auto &x : v)
    {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug_out()
{
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int mxN = 100000 + 11;

int L[4], C[4];
int n, s, f;
int d[mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // cin >> L[1] >> L[2] >> L[3] >> C[1] >> C[2] >> C[3];
    // cin >> n >> s >> f;
    // for (int i = 2; i <= n; ++i)
    //     cin >> d[i];
    //

    vector<int> a = {1,5,7,8,9,11,15,19,20};


    int v; cin >> v;

    int pos1 = lower_bound(a.begin(), a.end(), v) - a.begin();
    int pos2 = upper_bound(a.begin(), a.end(), v) - a.begin();
    dbg(a);
    string s1 = "lower_bound", s2 = "upper_bound"; 
    dbg(s1, pos1, *lower_bound(a.begin(), a.end(), v));
    dbg(s2, pos2, *upper_bound(a.begin(), a.end(), v));

    return 0;
}

