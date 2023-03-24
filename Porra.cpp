#include <bits/stdc++.h>
using namespace std;
char mt[51][51];
int dx[]={-1,0,1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};

void war(int n,int i,int j,int x, int y){
    for(int k=0;k<4;k++){
        x=i+dx[k];
        y=j+dy[k];
        if(x-1>=0&&y+1<n&&y-1>=0&&x+1<n&&mt[x][y]=='1'){
            cout<<'i'<<x<<" "<<'j'<<y<<endl;
            mt[x][y]='0';
            return war(n,i,j,x,y);
        }
    }
    mt[i][j]='0';
    cout<<endl;
}

int main(){
    
    int n;
    int cont=-1;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mt[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mt[i][j]=='1'){
                cont++;
                cout<<"ii"<<i<<" "<<"jj"<<j<<endl;
                war(n,i,j,0,0);
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mt[i][j];
        }
        cout<<endl;
    }
    cout<<cont<<endl;
}
