struct trem{
	char jogador;
	char cor;
	int torre;
};
class node{
	public:
	trem D;
	node *next;
	
	static node* montanode(trem T);
	static void desmontanode(node* p);
};

node* node::montanode(trem T){
	
	node *p = new node;
	if(p){
		p->D=T;
		p->next=0;
	}
	return p;
}
void node::desmontanode(node* P){
	delete P;
}

class stack{
	
	trem* T;
	int N;
	node* tp;
	
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
	
}

bool stack::push(trem t){
	
	node *p;
	p=node::montanode(t);
	
	if(!p) return false;
	
	p->next=tp;
	tp=p;
	N++;
	return true;

}
void stack::pop(){
	node *p;
	p=tp;
	tp=tp->next;
	node::desmontanode(p);
	N--;
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
	
	while(tp){
		node *p;
		p=tp;
		tp=tp->next;
		node::desmontanode(p);
	}
	N=0;
}

class queue{
	node* head;
	node* tail;
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
	head=tail=0;
	n=0;
}
queue::~queue(){
	while(head){
		node *p;
		p=head;
		head=head->next;
		node::desmontanode(p);
	}	
}
bool queue::push(trem T){
	node *p;
	p=node::montanode(T);
	if(!p) return false;
	if(!head) head=p;
	else tail->next=p;
	tail=p;
	n++;
	return true;
}
void queue::pop(){
	if(head){
		node* p=head;
		head=head->next;
		node::desmontanode(p);
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
	if(!head)return true;
	return false;
}
int queue::size(){
	return n;
}
void queue::clear(){
	while(head){
		node *p;
		p=head;
		head=head->next;
		node::desmontanode(p);
	}
	n=0;
}

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
        if(vet[i] == '2' ) player[i]=j2;
        if(vet[i] == '3' ) player[i]=j3;
        if(vet[i] == '4' ) player[i]=j4;
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
}
