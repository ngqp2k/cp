using namespace std;
#include <bits/stdc++.h>

const int N = 1e3+5;
int n, k, vis[N];
set<int> ke[N];

void ac() {
    puts("1.0");
    fputs("Correct", stderr);
    exit(0);
}
void wa() {
    puts("0.0");
    fputs("Wrong asnwer", stderr);
    exit(0);
}

int main (int argc, char ** argv) {
	ifstream inp (argv[1]);
    ifstream ans (argv[2]);
    ifstream out (argv[3]);

    int t;
    inp >> t;
    while (t--) {
        inp >> n >> k;
        for(int i=2; i<=n; ++i) {
            int j; inp >> j;
            ke[i].insert(j);
            ke[j].insert(i);
        }

        int mans, mout;
        ans >> mans;
        out >> mout;
        if (mans != mout) wa();

        int u, v, cnt = 0;
        ans >> u;
        out >> u;
        if (u != 1) wa();
        for(int i=1; i<=mans; ++i) {
            if (!vis[u]) vis[u] = 1, cnt += 1;
            ans >> v;
            out >> v;
            if (!ke[u].count(v)) wa();
            u = v;
        }
        if (!vis[u]) vis[u] = 1, cnt += 1;

        if (cnt != k) wa();

        for(int i=1; i<=n; ++i) vis[i] = 0;
        for(int i=1; i<=n; ++i) ke[i].clear();
    }

    ac();

    return 0;
}
