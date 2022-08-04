#include <bits/stdc++.h>
using namespace std;

#define TASK "REPLACESUM"

priority_queue <long long, vector <long long>, greater <long long> > pq;
int n, k;
long long res = 0;
const long long oo = 1e18;
int main(){
//    #ifndef ONLINE_JUDGE
//        freopen(TASK".INP","r",stdin);
//        freopen(TASK".OUT","w",stdout);
//    #endif
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        pq.push(x);
    }
    while (pq.size() > 1){
        long long lo = +oo, hi = -oo, sum = 0;
        int cnt = 0;
        while (!pq.empty()){
            ++cnt;
            if (cnt > k) break;
            long long x = pq.top();
            pq.pop();
            lo = min(lo, x);
            hi = max(hi, x);
            sum += x;
        }
        pq.push(sum);
        res += abs(lo - hi);
    }
    cout << pq.top() << '\n' << res;// << '\n';
}
