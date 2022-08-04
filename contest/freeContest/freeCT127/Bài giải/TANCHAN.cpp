#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int Sz = 3e5 + 5;
const ll MAXRANGE = 1e12;
const ll MINRANGE = -1e12;

struct Line {
  ll a, b;
  ll operator()(ll x) { 
  	return a * x + b; 
  }
};

struct Tree{
	Tree *lson, *rson;
	ll low, high;
	Line L;
	Tree(ll x, ll y, Line d) : low(x), high(y), L(d){
		lson = nullptr;
		rson = nullptr;
	}
};

void read(istream &cin);
void Pretreatment();
void Solve();
void ins(Tree *node, Line d);
ll get(Tree *node, ll pos);

ll a[Sz];
ll f[Sz];
ll sum[Sz];
Tree *root;
int n;

signed main(){

	read(cin);
	Pretreatment();
	Solve();

	return 0;
}

void read(istream &cin){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	return ;
}

void Pretreatment(){
	for(int i = 1; i <= n; i++){
		f[i] = f[i - 1] + i * a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	return ;
}

void Solve(){
	ll res = 0;
	int L, R = -1;
	Line d = {0, 0};
	root = new Tree(MINRANGE, MAXRANGE, d);

	for(int i = 1; i <= n; i++){
		//(-j * si + j * sj - fj + fi;
		ll temp = get(root, sum[i]) + f[i];

		if(temp > res){
			R = i;
			res = temp;
		}

		d = {-i, i * sum[i] - f[i]};
		ins(root, d);
	}

	for(L = R; L > 0; L--){
		ll d = (f[R] - f[L - 1]) - (L - 1) * (sum[R] - sum[L - 1]);
		if(d == res) break;
	}
	
	cout << res << endl;
	if(R != -1) cout << L << " " << R << endl;
  	else cout << -1 << endl;

  	return ;
}

void ins(Tree *node, Line d){

	ll mid = (node->low + node->high + 2 * MAXRANGE) / 2 - MAXRANGE;
	bool b1 = node->L(node->low) < d(node->low);
	bool b2 = node->L(mid) < d(mid);
	if(b2) swap(node->L, d);
 
	if(node->low == node->high) return ;

	if(b1 != b2){
		if(node->lson == nullptr)
			node->lson = new Tree(node->low, mid, d);
		else return ins(node->lson, d);
	}else{
		if(node->rson == nullptr)
			node->rson = new Tree(mid + 1, node->high, d);
		else return ins(node->rson, d);
	}
}

ll get(Tree *node, ll pos){
	if(node == nullptr) return 0;
	if(node->low == node->high) return node->L(pos);
	ll mid = (node->low + node->high + 2 * MAXRANGE) / 2 - MAXRANGE;
	if(pos <= mid) return max(node->L(pos), get(node->lson, pos));
	return max(node->L(pos), get(node->rson, pos));
}
