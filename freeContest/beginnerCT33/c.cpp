#include <bits/stdc++.h>
using namespace std;
#define maxN (long long)1000000000000

vector<int> prime;

void sieve(long long n) {
  bool check[1000007] = { 0 };
  long long i, j;
  check[0] = 1, check[1] = 1,
  check[2] = 0;

  for (i = 4; i <= n; i += 2)
    check[i] = true;

  for (i = 3; i * i <= n; i += 2)
    if (!check[i]) {
      for (j = i * i; j <= n; j += 2 * i)
        check[j] = true;
    }
  prime.push_back(2);
  for (int i = 3; i <= n; i += 2)
    if (!check[i])
      prime.push_back(i);

  return;
}

long long count(long long a[], int n, long long m){
  long long parity[3] = { 0 };
  for (int i = 1; i < (1 << n); i++) {
    long long mult = 1;
    for (int j = 0; j < n; j++)
      if (i & (1 << j))
        mult *= a[j];
    parity[__builtin_popcount(i) & 1]
      += (m / mult);
  }

  return parity[1] - parity[0];
}

long long countRelPrime(long long n, long long m)
{

  long long a[20];
  int i = 0, j = 0;
  long long pz = prime.size();
  while (n != 1 && i < pz) {
    if ((long long)prime[i]
        * (long long)prime[i]
      > n)
      break;
    if (n % prime[i] == 0)
      a[j] = (long long)prime[i], j++;

    while (n % prime[i] == 0)
      n /= prime[i];
    i++;
  }

  if (n != 1)
    a[j] = n, j++;
  return m - count(a, j, m);
}

void countRelPrimeInRange(long long n, long long l, long long r){
  sieve(sqrt(maxN));
  long long result = countRelPrime(n, r) - countRelPrime(n, l - 1);
  cout << result << "\n";
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    long long N; cin >> N;
    countRelPrimeInRange(N, 1, N);
  }
  return 0;
}
