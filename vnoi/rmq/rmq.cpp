#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define INF 1e9 + 7

using namespace std;

const int mxN = 1e5;

typedef pair<int, int> II;

int a[mxN];
int st[mxN * 3];
int n;

void print(){
	for(int i=0;i<=15;++i)
		cout << st[i] << " ";
}

void SpareTable(){
	int m[mxN][20];
	for(int i = 0; i < n; ++i)
		m[i][0] = i;
	
	for(int j = 1;(1 << j) <= n; ++j){
		for(int i = 0; i + (1 << j) - 1 < n; ++i){
			if (a[m[i][j - 1]] <= a[m[i + (1 << (j - 1))][j - 1]])
				m[i][j] = m[i][j - 1];
			else
				m[i][j] = m[i + (1 << (j - 1))][j - 1];
		}
	}
}

void initST(int node, int b, int e){
	if (b == e){
		st[node] = b;
		return;
	}

	int mid = (b + e) / 2;
	initST(node * 2, b, mid);
	initST(node * 2 + 1, mid + 1, e);
	st[node] = (a[st[node * 2]] <= a[st[node * 2 + 1]]) ? st[node * 2] : st[node * 2 +  1];
}

int qST(int node, int l, int r, int b, int e){
  if (e < l || b > r)
		return n + 1;
	if (b <= l && r <= e)
		return st[node];
	int mid = (l + r) / 2;
	int x = qST(node * 2, l, mid, b, e);
	int y = qST(node * 2 + 1, mid + 1, r, b ,e);
	if (a[x] <= a[y])
		return x;
	else
		return y;
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	a[n + 1] = INF;
	
	// SpareTable();
	initST(1, 0, n - 1);
	cout << qST(1, 0, n - 1, 5, 7);
}	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
