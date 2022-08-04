#include <iostream>
#include <cstring>
#include <math.h>
#include <cstdio>
#include <stack>

using namespace std;

const int N = 109;
const int M = 50009;
int p[N], d[N], v[N];
int g[N][N];
int fa[N];
int l[M];
char s[59], z[M][59];
int t[26] = {
    2, 2, 2,
    3, 3, 3,
    4, 4,
    1, 1,
    5, 5,
    6, 6,
    0, 7, 0,
    7, 7, 8,
    8, 8, 9,
    9, 9, 0
};

int nxt[59];

void getNext(int d[], int length)
{
    nxt[0] = 0;
    for(int i=1, k=0; i<length; i++)
    {
        while(k && d[i] != d[k])
            k = nxt[k-1];
        nxt[i] = d[i] == d[k] ? ++k : 0;
    }
}

void kmp(int b[], int d[], int len, int length, int pos)
{
    getNext(d, length);
    for(int i=0, k=0; i<len; i++)
    {
        while(k>0 && d[k] != p[i])
            k = nxt[k-1];
        if(d[k] == p[i])
            k++;
        if(k == length)
            g[i-length+1][i+1] = pos;
    }
}

bool solve(int len)
{
    memset(v, 0x3f, sizeof(v));
    v[0] = 0;
    for(int i=0; i<len; i++)
        for(int j=i+1; j<=len; j++)
            if(g[i][j] != -1 && v[i]+1 < v[j])
            {
                v[j] = v[i] + 1;
                fa[j] = g[i][j];
            }
    return v[len] < 0x3f3f3f3f;
}

void print(int now)
{
    if(now - l[fa[now]] > 0)
    {
        print(now-l[fa[now]]);
        printf(" ");
    }
    printf("%s", z[fa[now]]);
}

int main()
{
    int n;
    while(~scanf("%s", s))
    {
        if(s[0] == '-')
            break;
        memset(g, -1, sizeof(g));
        int len = strlen(s);
        for(int i=0; i<len; i++)
            p[i] = s[i]-'0';
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%s", z[i]);
            l[i] = strlen(z[i]);
            for(int j=0; j<l[i]; j++)
                d[j] = t[z[i][j]-'a'];
            kmp(p, d, len, l[i], i);
        }
        if(solve(len))
            print(len);
        else
            printf("No solution.");
        printf("\n");
    }
    return 0;
}