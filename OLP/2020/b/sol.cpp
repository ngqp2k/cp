#include <bits/stdc++.h>
using namespace std;


const int mxN = (int) 2e5 + 11;
int cnt[3][mxN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int k; cin >> k;
	string s; cin >> s;
	/*
	 * voi moi l tim r nho nhat, s[l..r] co it nhat "k" ki tu moi loai
	 * l : 1 -> n - 3k
	 *
	*/
	s = '#' + s;
	int n = (int)s.length();
	cout << s << "\n";
	cnt[0][0] = cnt[1][0] = cnt[2][0] = 0;
	for (int i = 1; i < n; ++i) {
		cnt[0][i] = cnt[0][i - 1];
		cnt[1][i] = cnt[1][i - 1];
		cnt[2][i] = cnt[2][i - 1];
		if (s[i] == 'V') cnt[0][i]++;
		else if (s[i] == 'C') cnt[1][i]++;
		else if (s[i] == 'A') cnt[2][i]++;
	}
	for (int i = 1; i < n; ++i)
		cout << cnt[2][i] << " ";

}
