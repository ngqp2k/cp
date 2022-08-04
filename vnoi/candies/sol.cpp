#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int mxN = 1e5 + 10; 

int N, M;
int a[mxN];

void test();

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for(int i = 1; i <= N; ++i)
		cin >> a[i];
	sort(a + 1, a + N + 1);
	test();
	
	auto it = upper_bound(a + 1, a + N + 1, 35);
	cout << *it << "\n";
	cout << (it - (a + 1));
	return 0;
}

void test() {
	for(int i = 1; i <= N; ++i)
		cout << a[i] << " ";
	cout << "\n";
}
