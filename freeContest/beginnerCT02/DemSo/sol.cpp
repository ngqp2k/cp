#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int cntPos = 0, cntNeg = 0;
	int n; cin >> n;
	for(int i = 1; i <= n ; ++i) {
		string s; cin >> s;
		if (s[0] == '-')
			cntNeg++;
		else if (s[0] != '0')
			cntPos++;
	}
	cout << cntNeg << " " << cntPos;
}
