#include<bits/stdc++.h>
using namespace std;
#define M 101
#define N 101
char mt[M][N];
bool vis[M][N];
int dx[]={-1,0,1,0,-1,1,1,-1},dy[]={0,1,0,-1,1,1,-1,-1},x,y;

void oil(int m,int n,int i,int j){
	vis[i][j]=true;
	
	for(int k=0;k<8;k++){
		x=i+dx[k];
		y=j+dy[k];
		if(x>=0&&x<m&&y>=0&&y<n&&mt[x][y]=='@'&&!vis[x][y]) oil(m,n,x,y);
	}
}

int main(){
	
	int m,n,cont;
	
	while(cin>>m>>n&&m!=0){
		cont=0;
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>mt[i][j];
			}
		}
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(mt[i][j]=='@'&&!vis[i][j]) cont++,oil(m,n,i,j);
			}
		}
		cout<<cont<<endl;
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				vis[i][j]=false;
	}
}
