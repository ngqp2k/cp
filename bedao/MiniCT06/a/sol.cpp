#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	double x, y;
	cin >> x >> y;
	cout << setprecision(9) << fixed;
	;
	auto f = [&] (double x, double y) {
		double a = 1;
		double b = 2 * x;
		double c = - (x * x + 2 * x * y);
		double delta = b * b - 4 * a * c;
		double x1, x2;
		if (delta < 0.0f) {
			return;
		}
		else if (delta == 0) {
			x1 = x2 = -b / (2 * a);

		}
		else {
			delta = sqrt(delta);
			x1 = (-b + delta) / (2 * a);
			x2 = (-b - delta) / (2 * a);
		}

		vector<double> ans(3);
		x1 = max(x1, x2);
		ans[1] = x1; // b
		ans[0] = y - x1; // a
		ans[2] = x + ans[0];
		sort(ans.begin(), ans.end());
		for (auto i: ans)
			cout << i << " ";
	};
	f(x, y);
}

