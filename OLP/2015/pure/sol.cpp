#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int m;
	string s;
	cin >> m >> s;
	char first_char = s[0];
	vector<int> pos;
	for (int i = 1; i <= m; ++i)
		if (s[i] == first_char)
			pos.push_back(i);

	for (int step: pos) {
		// cout << "------ step: " << step << "\n";
		// cout <<
		string s_temp = s.substr(0, step);
		for (int i = step; i < s.length(); i += step)
			if (i + step >= s.length()) {
				if (s.substr(i, s.length() - i) == s_temp.substr(0, s.length() - i)) {
					cout << s_temp;
					return 0;
				}
				else
					break;
			}
			else if (s.substr(i, step) != s_temp){
				break;
			}
		
	}
	cout << "NO";
}
