#include <bits/stdc++.h>
#define int long long

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);



	int N, K; std::cin >> N >> K;
	while(K > 0) {
		if (N % 200 == 0){
			N /= 200;
		}
		else {
			N = N * 1000 + 200;
			// std::cout << N << " ";
		}
		K--;
	}
	std::cout << N;
}