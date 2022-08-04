#define FO(i,a) for (int i=1;i<=a;i++)
#define FOR(i,a,b) for (int i=a; i<=b;i++)
#define FOR2(i) for(int i=-1; i<=1; i+=2)
#define MAX 300

#include <bits/stdc++.h>

using namespace std;


//string name = "Test10";
//ifstream fi("F:\\Competive\\CodeForces\\RECOVER\\triple\\"+ name +"\\TRIPLE.INP");
//ifstream fi2("F:\\Competive\\CodeForces\\RECOVER\\triple\\"+ name +"\\TRIPLE.OUT");
//ofstream fo("F:\\Competive\\CodeForces\\RECOVER\\triple\\"+ name +"\\MyAns.OUT");


int n,m,x,y,z,t;
int result[MAX][MAX], a[MAX][MAX];
bool kt[MAX][MAX],inQ[MAX][MAX];

vector<pair<int,int>> q;

int cal(int a, int b){
    return a > b ? a - b : 0;
}

int min(int a, int b){
	return a > b ? b : a;
}

void solve(int x, int y){
    FOR2(i){
        if ( (x + i > 0) && (x + i <= n) && !kt[x + i][y] && result[x + i][y] <= result[z][t] ){
            if (!inQ[x + i][y]){
                q.push_back(make_pair(x + i,y));
                inQ[x + i][y] = true;
            }
            result[x + i][y] = min(result[x][y] + cal(a[x + i][y], a[x][y]), result[x + i][y]);
        }
    }
    FOR2(i){
        if ( (y + i > 0) && (y + i <= m) && !kt[x][y + i] && result[x][y + i] <= result[z][t] ){
            if (!inQ[x][y + i]) {
                q.push_back(make_pair(x,y + i));
                inQ[x][y + i] = true;
            }
            result[x][y + i] = min(result[x][y] + cal(a[x][y + i], a[x][y]), result[x][y + i]);
        }
    }
	if (q.empty()) return ;
    int tmp = 0;
    FOR(i, 1, q.size()-1){
        if ( result[q[i].first][q[i].second] < result[q[tmp].first][q[tmp].second] ){
            tmp = i;
        }
    }
    kt[q[tmp].first][q[tmp].second] = true;
	x = q[tmp].first;
	y = q[tmp].second;
	q.erase(q.begin() + tmp);
    solve(x, y);
    return ;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>x>>y>>z>>t;
	FO(i,n){
        FO(j,m){
            cin>>a[i][j];
            inQ[i][j] = false;
            kt[i][j]  = false;
			result[i][j] = INT_MAX;
        }
    }

    kt[x][y] = true;
    inQ[x][y] = true;
	result[x][y]=0;
    solve(x, y);
    cout<<result[z][t]<<endl;
	/*FO(i,n){
        FO(j,m){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}*/
    system("pause");
	return 0;
}
