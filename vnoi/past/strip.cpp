// Strip - codeforces
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define INF 1e9 + 7

using namespace std;

const int mxN = 1e5;
const int LOG = 20;

typedef pair<int, int> II;
int n, l, s;
int a[mxN + 1], p_min[mxN + 1][LOG], p_max[mxN + 1][LOG];

void test(){
	int j = 2;
	for(int i = 1; i <= n; ++ i)
		cout << p_min[i][j] << " ";
	cout << "\n";
	for(int i = 1; i <= n; ++ i)
		cout << p_max[i][j] << " ";
}

void initPT(){
	for(int i = 1; i <= n; ++i){
		p_min[i][0] = i;
		p_max[i][0] = i;
	}

	for(int j = 1; (1 << j) <= n; ++j)
		for(int i = 1; i + (1 << j) - 1 <= n; ++i){
			if (a[p_min[i][j - 1]] <= a[p_min[i + (1 << (j - 1))][j - 1]])
				p_min[i][j] = p_min[i][j - 1];
			else if (a[p_min[i][j - 1]] > a[p_min[i + (1 << (j - 1))][j - 1]])
				p_min[i][j] = p_min[i + (1 << (j - 1))][j - 1];
			if (a[p_max[i][j - 1]] >= a[p_max[i + (1 << (j - 1))][j - 1]])
				p_max[i][j] = p_max[i][j - 1];
			else if (a[p_max[i][j - 1]] < a[p_max[i + (1 << (j - 1))][j - 1]])
				p_max[i][j] = p_max[i + (1 << (j - 1))][j - 1];
		}	
}

int getMin(int u, int v){
	int k = v - u + 1;
	for (int j = LOG; j >= 0; --j)
		if ((1 << j) <= k){
			if (a[p_min[u][j]] <= a[p_min[v - (1 << j) + 1][j]])
				return a[p_min[u][j]];
			else
				return a[p_min[v - (1 << j) + 1][j]];
		}
}

int getMax(int u, int v){
	int k = v - u + 1;
	for (int j = LOG; j >= 0; --j)
		if ((1 << j) <= k){
			if (a[p_max[u][j]] >= a[p_max[v - (1 << j) + 1][j]])
				return a[p_max[u][j]];
			else
				return a[p_max[v - (1 << j) + 1][j]];
		}
}

void solve(){
	cin >> n >> l >> s;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	initPT();

	int u = 1, cnt = 0;
	for(int i = u + 1; i <= n; ++i){
		int length = i - u + 1;
		if (length < l)
			if (getMax(u, i) - getMin(u, i) > s || i == n){
				cout << -1;
				exit(0);
			}
			else continue;
		// leng >= l
		if (getMax(u, i) - getMin(u, i) <= s) {
			if (i == n){
				cout << ++cnt;
				exit(0);
			}
			else continue; // dif <= s
		}
		// dif > s
		u = i - 1;
		cnt++;
		if (i == n){
			cout << cnt;
			exit(0);
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
