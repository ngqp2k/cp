#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 1e5 + 10; 

typedef pair<int, int> II;
II D[mxN];
int N;

bool cmp(II a, II b) {
	if (a.fi == b.fi)
		return a.se > b.se;
	else
		return a.fi < b.fi;
}

void print();

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		cin >> D[i].fi >> D[i].se;
	}

	sort(D + 1, D + 1 + N, cmp);

	print();
	return 0;
}

void print() {
	for(int i = 1; i <= N; ++i)
		cout << D[i].fi << " " << D[i].se << "\n";
}
