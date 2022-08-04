// Z Algorithm
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	while (cin >> s) {
		cout << s << " -- " << s.length() << "\n";
		int n = s.length();
		vector<int> z(n);
		int l = -1, r = -1;
		for (int i = 1; i < n; ++i) {
			if (i > r) {
				l = r = i;
				while (r < n && s[r] == s[r - l])
					r++;
				r--;
				z[i] = r - l + 1; 
			}
			else {
				int t = i - l;
				if (z[t] < r - i + 1)
					z[i] = z[t];
				else {
					l = i;
					while (r < n && s[r] == s[r - l])
						r++;
					r--;
					z[i] = r - l + 1;
				}
			}
		}
		for (int i: z)
			cout << i << " ";
		cout << "\n";
	}
}

