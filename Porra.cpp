

struct trem{
	char jogador;
	char cor;
	char torre;
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
	bool Push(trem t);
	void Pop();
	trem Top();
	bool Empty();
	int Size();
	void Clear();
	
};

stack::stack(){
	tp=0;
	N=0;
}
stack::~stack(){
	
}

bool stack::Push(trem t){
	
	node *p;
	p=node::montanode(t);
	
	if(!p) return false;
	
	p->next=tp;
	tp=p;
	N++;
	return true;

}
void stack::Pop(){
	node *p;
	p=tp;
	tp=tp->next;
	node::desmontanode(p);
	N--;
}
	
trem stack::Top(){
	
	trem t;
	
	if(tp) t=tp->D;
	return t;
}

bool stack::Empty(){
	if(!tp) return true;
	return false;
}

int stack::Size(){
	return N;
}	

void stack::Clear(){
	
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
	stack t1,t2,t3,t4,t5,t6;
	queue j1,j2,j3,j4;
	char vet[4];
	trem aux;

	for(int i=0;i<13;i++){
		cin>>aux.jogador>>aux.cor>>aux.torre;

		if(aux.jogador=='1') j1.push(aux);
		else if(aux.jogador=='2') j2.push(aux);
		else if(aux.jogador=='3') j3.push(aux);
		else j4.push(aux);
	}
	vet[0]=aux.jogador;
		for(int i=0;i<13;i++){
		cin>>aux.jogador>>aux.cor>>aux.torre;

		if(aux.jogador=='1') j1.push(aux);
		else if(aux.jogador=='2') j2.push(aux);
		else if(aux.jogador=='3') j3.push(aux);
		else j4.push(aux);
	}
	vet[1]=aux.jogador;
		for(int i=0;i<13;i++){
		cin>>aux.jogador>>aux.cor>>aux.torre;

		if(aux.jogador=='1') j1.push(aux);
		else if(aux.jogador=='2') j2.push(aux);
		else if(aux.jogador=='3') j3.push(aux);
		else j4.push(aux);
	}
	vet[2]=aux.jogador;
		for(int i=0;i<13;i++){
		cin>>aux.jogador>>aux.cor>>aux.torre;

		if(aux.jogador=='1') j1.push(aux);
		else if(aux.jogador=='2') j2.push(aux);
		else if(aux.jogador=='3') j3.push(aux);
		else j4.push(aux);
	}
	vet[3]=aux.jogador;
	char primeiro=vet[0],segundo=vet[1],terceiro=vet[2],quarto=vet[3];

	while(!t1.empty()||!t2.empty()!t3.empty()!t4.empty()!t5.empty()!t6.empty()){
	
		j1
	}
}
