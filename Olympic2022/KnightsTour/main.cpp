#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 2,  2,  1, -1, -2, -2, -1};
const int dy[] = {2, 1, -1, -2, -2, -1,  1,  2};

int n;
int a[100][100], check[100][100];
int tmp = 0;

void Try(int x, int y, int cnt) {
    if (cnt >= (n * n)) {
        ++tmp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n-----------------\n\n";
        if (tmp == 3)
            exit(0);
    }
    else {
        for (int i = 0; i < 8; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (0 <= u && u < n && 0 <= v && v < n && !check[u][v]) {
                check[u][v] = 1;
                a[u][v] = cnt;
                Try(u, v, cnt + 1);
                check[u][v] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    check[0][0] = 1;
    Try(0, 0, 1);

    cout << "\n";

    return 0;
}
