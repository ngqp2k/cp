#include <bits/stdc++.h>
using namespace std;

int main() {
	while (1) {
		int n1, m1;
		cout << "Enter size matrix 1: ";
		cin >> n1 >> m1;
		cout << "Enter matrix 1:\n";
		vector< vector<float> > a(n1, vector<float>(m1, 0.0f));
		for (int i = 0; i < n1; ++i) {
			for (int j = 0; j < m1; ++j)
				cin >> a[i][j];
		}
		cout << "Enter size matrix 2: ";
		int n2, m2;
		cin >> n2 >> m2;
		cout << "Enter matrix 2:\n";
		vector< vector<float> > b(n2, vector<float>(m2, 0.0f));
		for (int i = 0; i < n2; ++i) {
			for (int j = 0; j < m2; ++j)
				cin >> b[i][j];
		}
		if (m1 != n2) {
			cout << "m1 != n2\n";
			continue;
		}
		vector< vector<float> > res(n1, vector<float> (m2));
		for (int i = 0 ; i < n1; ++i) {
			for (int j = 0; j < m2; ++j) {
				res[i][j] = 0;
				for (int k = 0; k < n2; ++k)
					res[i][j] += a[i][k] * b[k][j];
			}
		}
		cout << "result:\n";
		for (int i = 0 ; i < n1; ++i) {
			for (int j = 0; j < m2; ++j) {
				cout << res[i][j] << " ";
			}
			cout << "\n";
		}
	}
}