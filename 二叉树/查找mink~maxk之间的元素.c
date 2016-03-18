#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define MINK 14
#define MAXK 29

typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode;
//释放申请的存储空间
void Free(Lnode *r);
//形参t用于存头结点的值，n为创建的单链表的结点数，由随机数产生
void build(Lnode *t,int n);

int main(){
	Lnode *h,*p;
	srand((unsigned)time(NULL));	//产生随机数
	h = (Lnode *)malloc(sizeof(Lnode));		//创建头结点
	h->next = NULL;
	build(h,rand()%30);  //调用build()创建单链表

	//找到mink~maxk之间的元素
	p = h->next;
	while(p != NULL){
		if(p->data > MINK && p->data < MAXK)
			printf("地址:%p 值:%d\t",p,p->data);
		p = p->next;
	}

	//释放单链表所占的空间
	Free(h->next);
	h->next = NULL;
    getch();
	return 0;
}

void Free(Lnode *r){
	Lnode *b;
	while(r != NULL){
		b = r->next;
		free(r);
		r = b;
	}
}

void build(Lnode *t,int n){
	int temp = 0;
	while(n){
		t->next = (Lnode*)malloc(sizeof(Lnode));
		t = t->next;
		t->data = temp + rand() % 10;
		temp = t->data;
		t->next = NULL;
		n--;
	}
}