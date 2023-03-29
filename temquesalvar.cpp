#include <iostream>
using namespace std;
int main(){
	stack tower[6];
    queue j1,j2,j3,j4;
	queue player[4];
    int contador=0;
    char vet[4];
	trem aux;

    for(int i=0;i<13*4;i++){

        cin>>aux.jogador>>aux.cor>>aux.torre;

        if(aux.cor=='A') vet[0]=aux.jogador;
        else if(aux.cor=='V') vet[1]=aux.jogador;
        else if(aux.cor=='R') vet[2]=aux.jogador;
        else if(aux.cor=='B') vet[3]=aux.jogador;

        if(aux.jogador=='1') j1.push(aux);
        else if(aux.jogador=='2') j2.push(aux);
        else if(aux.jogador=='3') j3.push(aux);
        else j4.push(aux);
    }
    
    for(int i=0;i<4;i++){
        if(vet[i] == '1' ) player[i]=j1;
        else if(vet[i] == '2' ) player[i]=j2;
        else if(vet[i] == '3' ) player[i]=j3;
        player[i]=j4;
    }

    while(contador<52){

        for(int k=0;k<4;k++){
            if(tower[(player[k].front().torre)-1].size()==6){
                
            }
            if(player[k].front().cor!='P'){
                tower[(player[k].front().torre)-1].push(player[k].front());
                player[k].pop();
            }
            else{
                if(tower[(player[k].front().torre)-1].size()>0)tower[(player[k].front().torre)-1].pop();
                player[k].pop();
            }
        }
        contador++;
    }
