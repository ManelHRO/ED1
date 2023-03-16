#pragma once

class trem{
	public:
	int number;
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

class stackvet{
	
	trem* T;
	int N;
	node* tp;
	
	public:
	stackvet();
	~stackvet();
	bool Push(trem t);
	void Pop();
	trem Top();
	bool Empty();
	int Size();
	void Clear();
	
};

stackvet::stackvet(){
	tp=0;
	N=0;
}
stackvet::~stackvet(){
	delete tp;
}

bool stackvet::Push(trem t){
	
	node *p;
	p=node::montanode(t);
	
	if(!p) return false;
	
	p->next=tp;
	tp=p;
	N++;
	return true;

}
void stackvet::Pop(){
	node *p;
	p=tp;
	tp=tp->next;
	node::desmontanode(p);
	N--;
}
	
trem stackvet::Top(){
	
	trem t;
	
	if(tp) t=tp->D;
	return t;
}

bool stackvet::Empty(){
	if(!tp) return true;
	return false;
}

int stackvet::Size(){
	return N;
}	

void stackvet::Clear(){
	
	while(tp){
		node *p;
		p=tp;
		tp=tp->next;
		node::desmontanode(p);
	}
	N=0;
}
