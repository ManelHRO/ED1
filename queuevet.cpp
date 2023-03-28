struct trem{
	int num;
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
}

