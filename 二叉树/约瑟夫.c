#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 3

typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode;
//形参t用于存头结点的值，n为创建的单链表的结点数，由随机数产生
Lnode* build(Lnode *t,int n);

int main(){
	Lnode *h,*p,*q,*last;
	int i,length;
	srand((unsigned)time(NULL));	//产生随机数
	h = (Lnode *)malloc(sizeof(Lnode));		//创建头结点
	h->next = NULL;
	length = rand()%30;
	last = build(h,length);  //调用build()创建单链表
	last->next = h->next;  //将单链表变成循环链表
	p = h->next;

	if(h->next == NULL)
		printf("链表为空!");
	else{
		while(length){
			for(i = 1;i < COUNT;i++)
				p = p->next;
			printf("%c\t",p->data);
			q = p->next;
			p->data = q->data;
			p->next = q->next;
			free(q);
			length--;
		}

	}

	h->next = NULL;
    getchar();
	return 0;
}


Lnode* build(Lnode *t,int n){
	int m = 'a';
	while(n){
		t->next = (Lnode*)malloc(sizeof(Lnode));
		t = t->next;
		t->data = m++;
		t->next = NULL;
		n--;
	}
	return t;
}