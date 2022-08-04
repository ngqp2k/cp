#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Sz = 1e4 + 4;

ll Count[Sz];
ll temp[Sz];
ll n, M;

ll Brute(vector<ll> &a){
	int res = 0;
	for(ll i : a)
		for(ll j : a)
			for(ll k : a)
				if(i*j*k % M == 0){
					res++;
					printf("(%lld, %lld, %lld) \n", i, j, k);
				}
	return res;
}

signed main(){

	cin >> n >> M;
	vector<ll> a;

	for(int i = 1; i <= n; i++){
		ll val;
		cin >> val;
		val %= M;
		a.push_back(val);
	}

	for(ll i : a)
		Count[i]++;
	ll res = 0;

	for(int i = 0; i < M; i++)
		for(int j = 0; j < M; j++)
			temp[i * j % M] += Count[i] * Count[j];

	for(int i = 0; i < M; i++)
		for(int j = 0; j < M; j++)
			if(i * j % M == 0)
				res += Count[i] * temp[j];

	cout << res << "\n";

	return 0;
}
