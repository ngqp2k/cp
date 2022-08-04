#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

bool isPrefix(string a, string b) {
    if (a.size() > b.size())
        return false;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
        return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    cout << (isPrefix(a, b) ? "Yes\n" : "No\n");
    return 0;
}