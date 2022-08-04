#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int N = 1e5 + 10; 

string s1, s2;

void solve1(string s1, string s2) {
	int cnt = s1.length() + s2.length();
	s1 += '@', s2 += '@';
	string res = "";
	while(res.length() < cnt) {
		if (s1 < s2){
			res = res + s1[0];
			s1.erase(0, 1);
		}
		else {
			res = res + s2[0];
			s2.erase(0, 1);
		}
	}

	cout << res << "\n";
}

void solve2(string s1, string s2) {
	string res = "";
	while(!s1.empty() && !s2.empty()) {
		if (s1 > s2){
			res = res + s1[0];
			s1.erase(0, 1);
		}
		else {
			res = res + s2[0];
			s2.erase(0, 1);
		}

		if (s1.empty()) res = res + s2;
		else if (s2.empty()) res = res + s1;
	}

	cout << res << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> s1 >> s2;

	solve1(s1, s2);
	solve2(s1, s2);

	return 0;
}

