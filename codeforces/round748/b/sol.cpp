#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = s.length();
		int ans[4];
		// check 00		
		ans[0] = 100;
		int posf0 = -1, posf5 = -1;
		for (int i = n - 1; i >= 0; --i)
			if (posf0 == -1 && s[i] == '0')
				posf0 = i;
			else if (posf5 == -1 && s[i] == '5')
				posf5 = i;
		// printf("pos0 = %d, pos5 = %d\n", posf0, posf5);
		int ans1 = n - posf0 - 1, ans2 = n - posf5 - 1;
		if (posf0 != -1)
			for (int i = posf0 - 1; i >= 0; --i)
				if (s[i] == '0' || s[i] == '5')
					break;
				else
					ans1++;
		if (posf5 != -1)
			for (int i = posf5 - 1; i >= 0; --i)
				if (s[i] == '2' || s[i] == '7')
					break;
				else
					ans2++;

		// cout << ans1 << " " << ans2 << " " << min(ans1, ans2) << "\n";
		cout << min(ans1, ans2) << "\n";
	}
}
