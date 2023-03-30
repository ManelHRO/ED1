#include <iostream>
using namespace std;

struct trem{
	int jogador;
	char cor;
	int torre;
};

class snode{
	public:
	trem D;
	snode *next;
	
	static snode* montanode(trem T);
	static void desmontanode(snode* p);
};

snode* snode::montanode(trem T){
	
	snode *p = new snode;
	if(p){
		p->D=T;
		p->next=0;
	}
	return p;
}
void snode::desmontanode(snode* P){
	if(P) delete P;
}

class stack{
	
	trem* T;
	int N;
	snode* tp;
	
	public:
	stack();
	~stack();
	bool push(trem t);
	void pop();
	trem top();
	bool empty();
	int size();
	void clear();
	
};

stack::stack(){
	tp=0;
	N=0;
}
stack::~stack(){
    snode *p;
	while(tp){
		p=tp;
		tp=tp->next;
		snode::desmontanode(p);
	}
}

bool stack::push(trem t){
	
	snode *p=snode::montanode(t);
	
	if(!p) return false;
	
	p->next=tp;
	tp=p;
	N++;
	return true;

}
void stack::pop(){
	snode *p=tp;
	if(p){
		tp=tp->next;
		snode::desmontanode(p);
		N--;
	}
}
	
trem stack::top(){
	
	trem t;
	
	if(tp) t=tp->D;
	return t;
}

bool stack::empty(){
	if(!tp) return true;
	return false;
}

int stack::size(){
	return N;
}	

void stack::clear(){
    snode *p;
	while(tp){
		p=tp;
		tp=tp->next;
		snode::desmontanode(p);
	}
	N=0;
}
//------------------------------------------------------------------------------------//
class qnode{
	public:
	trem D;
	qnode *next;
	
	static qnode* montanode(trem T);
	static void desmontanode(qnode* p);
};

qnode* qnode::montanode(trem T){
	
	qnode *p = new qnode;
	if(p){
		p->D=T;
		p->next=0;
	}
	return p;
}
void qnode::desmontanode(qnode* P){
	if(P) delete P;
}

class queue{
	qnode* head;
	qnode* tail;
	int n;
	
	public:
	queue();
	~queue();
	bool push(trem T);
	void pop();
	trem front();
	bool empty();
	int size();
	void clear();
};

queue::queue(){
	head=0;
    tail=0;
	n=0;
}
queue::~queue(){
    qnode *p;
	while(head){
		p=head;
		head=head->next;
		qnode::desmontanode(p);
	}	
}
bool queue::push(trem T){
	qnode* p=qnode::montanode(T);
	if(!p) return false;
	if(!head) head=p;
	else tail->next=p;
	tail=p;
    tail->next=0;
	n++;
	return true;
}
void queue::pop(){
	if(head){
		qnode* p=head;
		head=head->next;
		qnode::desmontanode(p);
	}
	if(!head) tail=0;
	n--;
}
trem queue::front(){
	trem T;
	if(head) T=head->D;
	return T;
}
bool queue::empty(){
    return !head;
}
int queue::size(){
	return n;
}
void queue::clear(){
    qnode *p;
	while(head){
		p=head;
		head=head->next;
		qnode::desmontanode(p);
	}
    n=0;
    tail=0;
}
//------------------------------------------------------------------------------------//


int main(){
	stack tower[6];
	queue player[4];
	int parada;
    int contador=13;
	trem aux;

    for(int i=0;i<13*4;i++){
        cin>>aux.jogador>>aux.cor>>aux.torre;
        if(aux.jogador==1) player[0].push(aux);
        else if(aux.jogador==2) player[1].push(aux);
        else if(aux.jogador==3) player[2].push(aux);
        else player[3].push(aux);
    }
	/*for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			cout<<player[i].front().jogador<<player[i].front().cor<<player[i].front().torre<<" ";
			player[i].pop();
		}
		cout<<endl<<endl;
	}*/
    
    while(contador--){
        for(int k=0;k<4;k++){
            if(tower[player[k].front().torre-1].size()==6){
				parada=0;
				
                for(int i=player[k].front().torre;parada<7;i=(i+1)%6,parada++){
                    if(tower[i].size()<6){

                        if(player[k].front().cor!='P'){
                        tower[i].push(player[k].front());
                        player[k].pop();
                        }
                        else{
                            if(tower[i].size()>0) tower[i].pop();
                            player[k].pop();
                        }
                    } 
                }
            }
            else{
                if(player[k].front().cor!='P'){
                    tower[(player[k].front().torre)-1].push(player[k].front());
                    player[k].pop();
                }
                else{
                    if(tower[(player[k].front().torre)-1].size()>0)tower[(player[k].front().torre)-1].pop();
                    player[k].pop();
                }
            }
        }
    }
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			cout<<tower[j].top().cor<<" ";
			tower[j].pop();
		}
		cout<<endl;
	}
}
//j=(j+1)%6
