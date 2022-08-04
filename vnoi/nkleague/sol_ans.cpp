#include<bits/stdc++.h>
#define maxn 1005
#define fs first
#define sc second
using namespace std;
int n,dd[maxn],num[maxn],pos[maxn],cnt,trace[maxn],f[maxn];
typedef pair<int,int> II;
II res;
vector<int> e[maxn];
void dfs(int u)
{
    if (dd[u]) return;
    dd[u]=1;
    for (int i=0;i<int(e[u].size());i++)
    {
        int v=e[u][i];
        dfs(v);
    }
    num[u]=cnt;
    pos[cnt]=u;
    cnt--;
}
int main()
{
    //freopen("NKLEAGUE.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cnt=n;
    for (int i=1;i<=n;i++)
    {
        char s[maxn];
        cin>>(s+1);
        for (int j=1;j<=n;j++)
            if (s[j]=='1')
        {
            e[i].push_back(j);
        }
    }
    for (int i=1;i<=n;i++)
        if (!dd[i])
        dfs(i);
    f[n]=1;
    for (int i=n-1;i>=1;i--)
   	{ 
        int u=pos[i];
        int k=1;
        for (int j=0;j<(int)e[u].size();j++)
        {
            int v=e[u][j];
            if (f[num[v]]+1>k)
            {
                trace[i]=num[v];
                k=f[num[v]]+1;
            }
        }
        f[i]=k;
    }
    for (int i=1;i<=n;i++)
        if (f[i]>res.fs)
    {
        res=II(f[i],i);
    }
    if (res.fs<n) cout<<-1;
    else
    {
        while(res.sc)
        {
            cout<<pos[res.sc]<<" ";
            res.sc=trace[res.sc];
        }
    }
    return 0;
}

