#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = (int) 1e9 + 7;
const int mxN = 100;

typedef pair<int, int> II;

vector<II> g[mxN + 1];
bool B[mxN + 1];
int arr[4];
int n;

class cmp{
	public:
	bool operator() (II a, II b){
		return a.se > b.se;
	}
};

int dijkstra(int start){
	vector<int> d(n + 1, INF);
	vector<int> cntPrev(n + 1, 0);
	vector<bool> selected(n + 1, false);
	priority_queue<II, vector<II>, cmp > q;

	d[start] = 0, cntPrev[start] = 1;
	q.push(II(start, d[start]));

	while(!q.empty()){
		int u = q.top().fi;
		q.pop();
		selected[u] = true;
		cout << u << "\n";
		
		if (cntPrev[u] == 4){
			return d[u];
		}

		for(auto v: g[u]){
	    if (!selected[v.fi] && d[u] + v.se < d[v.fi]){ // cap nhat
				d[v.fi] = d[u] + v.se;
				q.push(II(v.fi, d[v.fi]));
				if (B[v.fi] && true){
					cntPrev[v.fi] = cntPrev[u] + 1;
				}
			}
		}
	}
	return INF;
}

void solve(){
	cin >> n;
	memset(B, 0, sizeof(B));
	for(int i=0;i<4;++i){
		cin >> arr[i];
		B[arr[i]] = true;
	}
	int u, v, val;
	while(cin >> u >> v >> val){
		g[u].push_back(II(v, val));
		g[v].push_back(II(u, val));
		
	}
	cout << dijkstra(4) << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
