#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode,*Linklist;

//释放申请的存储空间
void Free(Lnode *r);

//形参t用于存头结点的值，n为创建的单链表的结点数，由随机数产生
void build(Lnode *t,int n);

int main(){
	Lnode *p,*q;
	Linklist h;
	srand((unsigned)time(NULL));	//产生随机数
	h = (Lnode *)malloc(sizeof(Lnode));		//创建头结点
	h->next = NULL;
	build(h,rand()%30);  //调用build()创建单链表

	//找出中间结点，返回其地址
	p = h;
	q = h;
	if(h->next == NULL)
		printf("单链表为空!");
	else{
		p = p->next;
		q = q->next->next;
		while(q != NULL && q->next != NULL){
			p = p->next;
			q = q->next->next;
		}
		if(q == NULL)
			printf("中间结点的地址:%p",p);
		else
			printf("有偶数个结点!");
	}
	//释放单链表所占的空间
	Free(h->next);
	h->next = NULL;
    getchar();
	return 0;
}

void build(Lnode *t,int n){
	while(n){
		t->next = (Lnode*)malloc(sizeof(Lnode));
		t = t->next;
		t->data = rand() % 20;
		t->next = NULL;
		--n;
	}
}

void Free(Lnode *r){
	Lnode *b;
	while(r != NULL){
		b = r->next;
		free(r);
		r = b;
	}
}