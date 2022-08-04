#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int Sz = 3e5 + 5;

int n;
int a[Sz];

bool check(ll res, ll out, ll l, ll r){
	if(res != out) return false;
	ll w = 0;
	for(int i = l; i <= r; i++) w += (i - l + 1) * a[i];
	return w == out;
}

signed main(int argc, char **argv){

	ifstream inp(argv[1]);
	
	inp >> n;
	for(int i = 1; i <= n; i++) 
		inp >> a[i];

	ll res, temp, x, y;

	ifstream ans(argv[2]);
	ans >> res;
	
	ifstream out(argv[3]);
	out >> temp >> x >> y;

	if(check(res, temp, x, y)) {
		puts("1.0");
		fputs("Correct", stderr);
	}else{
		puts("0.0");
		fputs("Wrong answer", stderr);
	}

	return 0;
}