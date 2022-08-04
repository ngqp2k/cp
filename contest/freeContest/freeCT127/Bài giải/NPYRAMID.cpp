#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int tt; cin >> tt;
    while (tt--) 
    {
        int n, v; cin >> n >> v;
        for (int i=1; i<=n; ++i) 
        {
            cout << v;
            for (int j=1; j<i; ++j) 
            {
                cout << " 0";
            }
            cout << endl;
        }
    }
}