#include <bits/stdc++.h>
using namespace std;

void mulBigNum(int val, vector<int> &a) {
    int mem = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        int num = a[i] * val + mem;
        a[i] = num % 10;
        mem = num / 10;
    }
    while (mem != 0) {
        a.push_back(mem % 10);
        mem = mem / 10;
    }
}

void powerBigNum(int val, int n, vector<int> &ans) {
    if (n == 0) { ans.push_back(1); return; }
    int tmp = val;
    while (tmp != 0) { ans.push_back(tmp % 10); tmp = tmp / 10; }
    for (int i = 2; i <= n; i++) mulBigNum(val, ans);
    //reverse(ans.begin(), ans.end());
}

bool compare(vector<int> a, vector<int> b) {
    if (a.size() > b.size()) return true; // a > b
    if (a.size() < b.size()) return false; // a < b
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > b[i]) { return true;}
        if (a[i] < b[i]) { return false;}
    }
    return true;
}

vector<int> subBigNum(vector<int> a, vector<int> b, bool &ok) {
    vector<int> ans;
    ok = false;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (!compare(a, b)) {
        ok = true;
        swap(a, b);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int borrow = 0;
    for (int i = 0; i < b.size(); ++i) {
        int s = a[i] - b[i] - borrow;
        if (s < 0) { s += 10; borrow = 1; }
        else borrow = 0;
        ans.push_back(s);
    }
    if (borrow > 0) {
        for (int i = b.size(); i < a.size(); ++i) {
            int s = a[i] - borrow;
            if (s < 0) { s += 10; borrow = 1; }
            else borrow = 0;
            ans.push_back(s);
        }
    }
    else {
        for (int i = b.size(); i < a.size(); ++i)
            ans.push_back(a[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    vector<int> num2, num1;
    int a = 1991, b = 1998;
    //1499 1997
    // cin >> a >> b;
    clock_t aa = clock();
    powerBigNum(a, b, num1);
    powerBigNum(b, a, num2);
    bool minus;
    vector<int> res = subBigNum(num1, num2, minus);
    reverse(res.begin(), res.end());
    while (*res.begin() == 0 && res.size() > 1) {
        res.erase(res.begin(), res.begin() + 1);
    }
    if (minus) cout << '-';
    for (int i: res)
        cout << i;
    clock_t bb = clock();
    cout << "\nTime: " << (bb - aa) * 1.0 / 1000;
    return 0;
}