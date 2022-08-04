#include<bits/stdc++.h>
using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 80;

void solve(){
	int s1, s2, s3; cin >> s1 >> s2 >> s3;
	int cnt[mxN + 1];
	int maxCnt = 0;
	memset(cnt, 0, sizeof(cnt));
	for(int i=1;i<=s1;++i)
		for(int j=1;j<=s2;++j)
			for(int k=1;k<=s3;++k){
				cnt[i + j + k]++;
				maxCnt = max(maxCnt, cnt[i + j + k]);
			}
	for(int i=1;i<=80;++i)
		if (cnt[i] == maxCnt){
			cout << i;
			break;
		}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
