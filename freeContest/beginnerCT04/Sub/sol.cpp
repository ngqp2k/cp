#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

int findSub1(vector<int> a){
  if (*max_element(a.begin(), a.end()) <= 0)
    return *max_element(a.begin(), a.end());
  int sum = 0;
  for(int i: a)
    sum = max(sum, sum + i);
  return sum;
}

int findSub2(vector<int> a){
  if (*max_element(a.begin(), a.end()) <= 0)
    return *max_element(a.begin(), a.end());
  int sum = 0, maxSum = *max_element(a.begin(), a.end());
  for(int i = 0; i < a.size(); ++i) {
    sum = max(sum + a[i], (int) 0);
    maxSum = max(maxSum, sum);
  }
  return maxSum;
}


int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("in", "r", stdin);
  freopen("ou", "w", stdout);
  int T; cin >> T;
  while (T--){
    int N; cin >> N;
    vector<int> a(N);
    for(int &x: a) cin >> x;
    cout << findSub1(a) << " " << findSub2(a) << "\n";
  }
}