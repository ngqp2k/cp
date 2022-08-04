#include <bits/stdc++.h>
#define nmax 15
using namespace std;
int ans[nmax], sum[nmax];
void find_hamiltonian_paths(int adj[nmax][nmax], int n)
{
  bool dp[nmax][1 << nmax] = {0};
  int i, j, k;
  for (i = 0; i < n; i++) {
    dp[i][1 << i] = 1;
    ans[i] = 0; sum[i] = i + 1;
  }

  int limit = 1 << n;
  for (i = 0; i < limit; i++)
  {
    int s = 0, count = 0, temp = i;
    while (temp)
    {
      // s: tong so dinh co trong mat na i
      s += log2(temp & -temp) + 1; // log2(a & -a) tra ve bit bit 1 thap nhat cua a
      temp &= temp - 1; // a & (a - 1) bo bit 1 thap nhat chua a
      // count: so dinh co trong mat na i
      count++;
    }
    for (j = 0; j < n; j++) {
      if (i & (1 << j)) {
        for (k = 0; k < n; k++)
          if (k != j && adj[k][j] && (i & (1 << k))  && dp[k][i ^ (1 << j)])
          {
            // ton tai dinh k ke voi j, co duong di toi k trong mat na i
            dp[j][i] = 1; // danh dau
            ans[j] = max(ans[j], count - 1); // If ans[j] > coutn - 1
            // ans[j]: so
            if (ans[j] == count - 1)
              sum[j] = max(sum[j], s);
            break;
          }
      }
    }
  }
  /*for(i=0;i<n;i++)
    printf("%d %d\n",ans[i],sum[i]);*/
  //printf("\n");
}
int gcd(int a, int b) {return (b) ? gcd(b, a % b) : a;}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int n, m, i, adj[nmax][nmax] = {0};
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
    {
      int x, y;
      scanf("%d%d", &x, &y);
      adj[x - 1][y - 1] = adj[y - 1][x - 1] = 1;
    }
    find_hamiltonian_paths(adj, n);
    int minn, maxx; minn = maxx = sum[0];
    for (i = 1; i < n; i++)
    {
      if (minn > sum[i])minn = sum[i];
      if (maxx < sum[i])maxx = sum[i];
    }
    int hcf = gcd(maxx, minn);
    printf("%d %d\n", maxx / hcf, minn / hcf);
  }
  return 0;
}
