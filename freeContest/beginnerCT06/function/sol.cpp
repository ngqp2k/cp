#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	int a, b, c, x;
	cin >> a >> b >> c >> x;
	int ans = a * x * x + b * x + c;
	cout << ans;
}

