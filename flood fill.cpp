#include <bits/stdc++.h>
using namespace std;
#define N 100
bool vis[N][N];
char adjlist[N][N];
int dx[] = {-1,0,1,0,-1,-1,1,1};
int dy[] = {0,1,0,-1,1,-1,-1,1};
int x, y, m, n;
void dfs(int i, int j){
    vis[i][j] = true;
    for(int k=0; k<8; k++){
		x = dx[k] + i;
		y = dy[k] + j;
		
        if(x >-1 and x < m and y >-1 and y < n and adjlist[x][y] == '@' and !vis[x][y]){
			//cout << "x = " << x << " y = " << y << '\n';
            dfs(x,y);
		}
    }
}
