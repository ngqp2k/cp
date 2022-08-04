#include <bits/stdc++.h>
using namespace std;

const int mxN = (int) 1e6 + 11;

int a[mxN];
int n;

struct BIT {
  vector<int> f;
  int n;
  BIT(int n): n(n), f(n + 10, 0) {}
  int getSum(int i) {
    int res = 0;
    for(; i; i -= i & -i)
      res += f[i];
    return res;
  }
  void add(int i, int val) {
    for (; i <= n; i += i & -i)
      f[i] += val;
  }
};

long long solvea() {
  BIT f(n);
  int cnt = 0; long long ans = 0;
  vector<int> p(4, -1);
  for (int i = 1; i <= n; ++i)
    if (a[i] > 0) {
      if (p[1] == -1)
        p[1] = i, f.add(a[i], 1), cnt++;
      else if (p[2] == -1)
        f.add(a[i], 1), cnt++;
    }
    else
      if (p[1] == -1) continue;
      else 
        if (p[2] == -1) p[2] = i;
        else {
          p[3] = i;
          break;
        }
  if (p[3] == -1) return 0;
  for (int i = p[3] + 1; i <= n; ++i) {
    if (a[i] < 0) {
      for (int j = p[2] + 1; j < p[3]; ++j)
        f.add(a[j], 1), cnt++;
      p[2] = p[3], p[3] = i;
    }
    else
      ans += (long long) cnt - f.getSum(a[i]);
  }
  for (int i = 1; i <= 10; ++i) 
    cout << f.f[i] << " ";
  cout << "\n";
  return ans;
}

long long solveb() {
  BIT f(n);
  long long ans = 0;
  vector<int> p(4, -1);
  for (int i = 1; i <= n; ++i)
    if (a[i] < 0) {
      if (p[1] == -1)
        p[1] = i, f.add(-a[i], 1);
      else if (p[2] == -1)
        f.add(-a[i], 1);
    }
    else
      if (p[1] == -1) continue;
      else
        if (p[2] == -1) p[2] = i;
        else {
          p[3] = i;
          break;
        }
  if (p[3] == -1) return 0;
  for (int i = p[3] + 1; i <= n; ++i) {
    if (a[i] > 0) {
      for (int j = p[2] + 1; j < p[3]; ++j)
        f.add(-a[j], 1);
      p[2] = p[3], p[3] = i;
    }
    else
      ans += (long long)f.getSum(-a[i] - 1);
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  cout << solvea() << solveb();
}
