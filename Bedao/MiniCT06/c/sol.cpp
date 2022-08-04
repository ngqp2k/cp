#include <bits/stdc++.h>
using namespace std;

const int MOD = 727355608;

long long pown(int n, int x) {
	if (x == 0)
		return 1;
	long long ans = pown(n, x / 2);
	if (x % 2 == 0)
		return (ans % MOD * ans % MOD) % MOD;
	else
		return (ans % MOD * ans % MOD * n % MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int s, na, nb, nc; cin >> s >> na >> nb >> nc;
	
	int nd = s - na - nb - nc;

	vector<int> a(s);

	int left = 0, right = s - 1;

	while (na >= 2) {
		a[left] = a[right] = 1;
		na -= 2;
		left++, right--;
	}

	bool ok = true;
	int mid = s / 2;

	if (na == 1) {
		ok = false;
		a[mid] = 1;
	}

	while (nd >= 2) {
		a[left] = a[right] = 0;
		nd -= 2;
		left++, right--;
	}

	if (nd == 1)
		if (ok) {
			ok = false;
			a[mid] = 0;
		}
		else {
			cout << "Bedao!";
			return 0;
		}
	
	while (nb >= 2) {
		a[left] = a[right] = 2;
		nb -= 2;
		left++, right--;
	}

	if (nb == 1)
		if (ok) {
			ok = false;
			a[mid] = 2;
		}
		else {
			cout << "Bedao!";
			return 0;
		}

	while (nc >= 2) {
		a[left] = a[right] = 0;
		nc -= 2;
		left++, right--;
	}

	if (nc == 1)
		if (ok) {
			ok = false;
			a[mid] = 3;
		}
		else {
			cout << "Bedao!";
			return 0;
		}

	long long ans = 0;

	for (int i = (int) a.size() - 1; i >= 0; --i) {
		if (a[i] == 1)
			ans += pown(2, (i * 2)) % MOD;
		else if (a[i] == 2)
			ans += pown(2, (i * 2 + 1)) % MOD;
		else if (a[i] == 3)
			ans += (pown(2, (i * 2)) + pown(2, (i * 2 + 1))) % MOD;
	}

	cout << ans;
}
