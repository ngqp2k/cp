#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first)
				return a.second < b.second;
		else
				return a.first < b.first;
}

// ifstream fi("input.inp");
// ofstream fo("output.out");

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i].first = abs(x) + abs(y);
        a[i].second = i;
    }
		sort(a.begin(), a.end(), cmp);
		// sort(a.begin(), a.end());
    vector<int> ans;
    int time = 0;
    for (int i = 0; i < n; ++i)
        if (a[i].first - time == 0) {
            cout << -1;
            return 0;
        }
        else {
            time++;
            ans.push_back(a[i].second);
        }
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i] + 1<< " ";
    return 0;
}
