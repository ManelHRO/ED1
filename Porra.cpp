#include <bits/stdc++.h>
#define N 51
using namespace std;
char mt[N][N];
bool vis[N][N];
int dx[]={-1,0,1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};
int x,y;

void war(int n,int i,int j){
	vis[i][j] = true;
    for(int k=0;k<8;k++){
        x=i+dx[k];
        y=j+dy[k];
        if(x>=0&&y<n&&y>=0&&x<n&&mt[x][y]=='1'&&!vis[x][y]){
            return war(n,x,y);
        }
    }
}

int main(){
    
    int n,cont,k=1;
    
    while(cin>>n){
			cont=-1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>mt[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(mt[i][j]=='1'&&!vis[i][j]){
					cont++;
					war(n,i,j);
				}
			}
		}
		cout<<"Image number "<<k++<<" contains "<<cont<<" war eagles."<<endl;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) 
				mt[i][j]=false;
	}
}
