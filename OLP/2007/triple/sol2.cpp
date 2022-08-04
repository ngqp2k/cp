#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define MAX 10000

#include <iostream>
#include <algorithm>
#include <map>
#include <ctime>
#include <fstream>

using namespace std;

int n;
map<int, bool> f;
int a[MAX], b[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	FOR(i, 0, n - 1) {
		cin >> a[i];;
		f[a[i]] = true;
	}
	sort(a, a + n); //7 3 1 5 2 -7 0 -1

	FOR(i, 0, n - 3) { // chừa 2 số cuối
		FOR(j, i + 1, n - 2) { // chừa 1 số cuối
			if (f[a[j] * 2 - a[i]]) { // tồn tại số tiếp theo tương ứng ?
				cout << "YES " << a[i] << " " << a[j] << " " << a[j] * 2 - a[i] << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}