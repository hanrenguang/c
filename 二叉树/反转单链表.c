#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Lnode{

	int data;

	struct Lnode *next;

}Lnode;

//释放申请的存储空间
void Free(Lnode *r);

//形参t用于存头结点的值，n为创建的单链表的结点数，由随机数产生
void Build(Lnode *t,int n);

//打印地址，验证是否反转
void Print(Lnode *m);



int main(){

	Lnode *h,*p,*q,*r;

	srand((unsigned)time(NULL));	//产生随机数

	h = (Lnode *)malloc(sizeof(Lnode));		//创建头结点

	h->next = NULL;

	Build(h,rand()%30);  //调用build()创建单链表

	
	printf("反转之前单链表结点的地址依次为:\n");

	Print(h->next);  //打印反转之前单链表的地址

	
	//实现单链表的反转

	if(h->next != NULL && h->next->next != NULL){
		p = h;
		q = p->next;
		r = q->next;
		q->next = NULL;

		while(r){
			p = q;
			q = r;
			r = r->next;
			q->next = p;
		}

		h->next = q;

	}


	printf("反转之后单链表结点的地址依次为:\n");

	Print(h->next);    //打印反转后的单链表的地址

	
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



void Build(Lnode *t,int n){

	while(n){

		t->next = (Lnode*)malloc(sizeof(Lnode));

		t = t->next;

		t->data = rand() % 20;

		t->next = NULL;

		n--;

	}

}



void Print(Lnode *m){

	if(m == NULL)

		printf("单链表为空!");

	else{

		while(m){

			printf("%p\t",m);

			m = m->next;

		}

	}

	printf("\n");

}