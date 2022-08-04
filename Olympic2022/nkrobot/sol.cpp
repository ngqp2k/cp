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

int a[11];
char rooms[11];
vector<int> robots[11];
string ans = "";
int mnCnt = 1000000000;

void solve() {
    vector<int> cnt(11, 0);
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= a[i]; ++j) {
            for (int room : robots[i])
                cnt[room]++;
        }
    }
    for (int i = 1; i <= 9; ++i) {
        if (rooms[i] == 'T') {
            if (cnt[i] % 3 != 0)
                return;
        }
        else if (rooms[i] == 'X') {
            if ((cnt[i] - 2) % 3 != 0)
                return;
        }
        else if (rooms[i] == 'V') {
            if ((cnt[i] - 1) % 3 != 0)
                return;
        }
    }

    int temp[11];
    for (int i = 1; i <= 9; ++i)
        temp[i] = a[i];

    string tmp = "";

    int tmpCnt = 0;

    for (int i = 1; i <= 9; ++i) {
        tmpCnt += temp[i];
        while (temp[i] != 0) {
            tmp = tmp + to_string(i);
            temp[i]--;
        }
    }

    if (tmpCnt <= mnCnt) {
        mnCnt = tmpCnt;
        ans = tmp;
    }
}

void Try(int i) {
    if (i > 9) {
        solve();
    }
    else {
        for (int j = 0; j < 3; ++j) {
            a[i] = j;
            Try(i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 9; ++i) {
        string s;
        cin >> s;
        for (char ch : s)
            robots[i].push_back((ch - '0'));
    }

    for (int i = 1; i <= 9; ++i)
        cin >> rooms[i];

    Try(1);

    if (ans != "") {
        cout << ans << "\n";
    }
    else {
        cout << 0 << "\n";
    }

    return 0;
}
