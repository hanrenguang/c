#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode;
//释放申请的存储空间
void Free(Lnode *r);
//形参t用于存头结点的值，n为创建的单链表的结点数，由随机数产生
void build(Lnode *t,int n);

int main(){
	Lnode *h,*p,*q;
	int length,k,i;
	scanf("%d",&k);  //输入要找的倒数第几个结点
	srand((unsigned)time(NULL));	//产生随机数
	h = (Lnode *)malloc(sizeof(Lnode));		//创建头结点
	h->next = NULL;
	length = rand()%30;
	build(h,length);  //调用build()创建单链表

	//找出倒数第K个结点
	p = h->next;
	q = h->next;
	if(length < k)
		printf("单链表的长度小于k!");
	else{
		for(i = 0;i < k;i++)
			p = p->next;
		while(p != NULL){
			p = p->next;
			q = q->next;
		}
		printf("倒数第k个结点的值和地址为:%d\t%p",q->data,q);
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
	while(n){
		t->next = (Lnode*)malloc(sizeof(Lnode));
		t = t->next;
		t->data = rand() % 20;
		t->next = NULL;
		n--;
	}
}