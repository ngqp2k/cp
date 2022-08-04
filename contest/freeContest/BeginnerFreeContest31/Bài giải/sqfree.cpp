#include <bits/stdc++.h>

#define int long long
#define rep(i,a,b) for (int i=a; i<(b); ++i)
#define pb push_back
using namespace std;
typedef vector<int> vi;
const int maxx = 1e7;
int x;

int sieve[maxx+1];
vi primes;
void init() {
	memset(sieve, true, sizeof(sieve));
	sieve[1] = false;
	for (int i=2; i*i<=maxx; ++i) {
		if (sieve[i]) {
			for (int j=i*2; j<=maxx; j+=i) sieve[j] = false;
		}
	}
	rep(i,2,maxx+1) if (sieve[i]) primes.pb(i);
}

bool is_prime(int x) {
	if (x<=maxx) return sieve[x];
	for (int i=2; i*i<=x; ++i) if (x%i==0) return false;
	return true;
}
	
main() {
	ios_base::sync_with_stdio(0);
	init();
	cin >> x;
	for (int u: primes) {
		if (x%u==0) {
			x/=u;
			if (x%u==0) { cout << "YES"; return 0; }
		}
	}

	int p = sqrt(x);
	while (p*p<x) p++;
	while (p*p>x) p--;

	if (p*p==x and is_prime(p)) { cout << "YES"; return 0; }

	cout << "NO";
	return 0;
}
