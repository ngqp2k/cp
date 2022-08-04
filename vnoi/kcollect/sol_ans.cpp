#include <bits/stdc++.h>

using namespace std;
 
const int maxN = 100010;
const int INF  = 1e9 + 7;
 
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0,  0, 1, 0,-1};

int m, n;
char a[maxN];
int val[maxN], totalScc[maxN];

/* Lưu đồ thị ban đầu*/
vector <int> g[maxN];

/* Lưu đồ thị mới*/
vector <int> h[maxN];

/* Kỹ thuật "Biến mảng 2 chiều thành mảng 1 chiều" */
int getId(int i, int j){
    return (i - 1) * n + j;
}

/* Kiểm tra ô (i, j) có được đi vào không? */
bool check(int i, int j) {
    if (a[getId(i, j)] == '#') return false;
    return (i >= 1 && j >= 1 && i <= m && j <= n);
}

/* Tìm thành phần liên thông mạnh*/
int root[maxN];
int low[maxN], num[maxN];
bool deleted[maxN];
int timeDfs = 0, scc = 0;
stack <int> st;
 
void dfs(int u) {
    low[u] = num[u] = ++timeDfs;
    st.push(u);
    for (int v : g[u]) {
        if (deleted[v]) continue;
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
 
    if (num[u] == low[u]) {
        scc++;
        int v;
        do {
            v = st.top();
            st.pop();
            deleted[v] = true;

            /* Tính tổng giá trị kinh tế của thành phần liên thông */
            totalScc[scc] += val[v];

            /*Đỉnh scc sẽ là đỉnh ảo đại diện cho v trong đồ thị DAG*/
            root[v] = scc;
        } while (v != u);
    }
}

void test();
 

/* Quy hoạch động trên đồ thị DAG */
int f[maxN];

int solve(int u) {
    if (h[u].empty()) return totalScc[u];
    if (f[u] != -1) return f[u];
    int cur = -INF;
    for (int v : h[u]) cur = max(cur, solve(v) + totalScc[u]);
    return f[u] = cur;
}
 
int main() {
    /* Xử lý dữ liệu đầu vào */
    freopen("in2", "r", stdin);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            int u = getId(i, j);
            cin >> a[u];
            val[u] = (a[u] >= '0' && a[u] <= '9') ? a[u] - '0' : 0;
        }

    /* Xây dựng đồ thị ban đầu */ 
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int u = getId(i, j);
            if (a[u] == '#') continue;
            if (check(i, j + 1)) g[u].push_back(getId(i, j + 1));
            if (check(i + 1, j)) g[u].push_back(getId(i + 1, j));

            if (a[u] == 'W' && check(i, j - 1)) 
                g[u].push_back(getId(i, j - 1));
            
            if (a[u] == 'N' && check(i - 1, j)) 
                g[u].push_back(getId(i - 1, j));
        }
    }

   // test();

    /* Tìm thành phần liên thông mạnh*/ 
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j){
            int u = getId(i, j);
            if (!num[u] && check(i, j)) dfs(u);
        }

    /* Xây dựng đồ thị mới */ 
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!check(i, j)) continue;
            int u  = getId(i, j);
            int ru = root[u];
            for (int v : g[u]) {
                int rv = root[v];
                if (ru != rv) {
                /* Có cung đi từ ru đến rv trên đồ thị mới do đỉnh 
                u trong TPLTM ru đi được tới đỉnh v trong TPLTM rv*/
                    h[ru].push_back(rv);
                }
            }
        }
    }
    fill(f, f + m * n + 1, -1);
    cout << solve(root[getId(1, 1)]);
}

void test(){
    for(int i = 1;i<=n*m;++i){
        cout << i << ": ";
        for(int v: g[i])
            cout << v << " ";
        cout << "\n";
    }
    exit(0);
}