#include<bits/stdc++.h>
using namespace std;

int main(){
	// 19260817 233 264
	int n = 61745;
	for(int i=1;i<=1000000;++i)
		if ((n - (i * 264)) % 233 == 0){
			cout << i;
			return 0;
		}
	cout << "\nss";
	return 0;
}
