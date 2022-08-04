#include<bits/stdc++.h>
using namespace std;

void solve();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

void solve(){
	int a, b; cin >> a >> b;
	vector<bool> arrPN(b + 1, true);
	arrPN[0] = false;
	arrPN[1] = false;
	for(int i=2; i * i <= b; i++){
		if (arrPN[i]){
			for(int j = i * 2; j <= b; j = j + i){
				arrPN[j] = false;
			}
		}
	}
	for(int i=a;i<=b;++i)
		if (arrPN[i])
			cout << i << " ";
}

