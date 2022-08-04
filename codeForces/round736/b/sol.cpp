#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 1e5 + 10; 

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		string s1, s2; cin >> s1 >> s2;
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			if (s2[i] == '0')
				continue;
			// s2[i] = 1
			if (s1[i] == '0') {
				ans++;
			   	continue;
			}
			if (i > 0 && s1[i - 1] == '1'){
				ans++; s1[i - 1] = '0';
				continue;
			}
			if (i < n - 1 && s1[i + 1] == '1') {
				ans++, s1[i + 1] = '0';
				continue;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
