#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <time.h>

typedef struct Lnode{

	int data;

	struct Lnode *next;

}Lnode;

//释放申请的存储空间

void Free(Lnode *r,Lnode *t);
//形参t用于存头结点的值，n为创建的单链表的结点数，由随机数产生
void build(Lnode *t,int n);
//判断并输出交点,长度较长的单链表传给m，短的传给n，l为两者长度差的绝对值
Lnode* judge(Lnode *m,Lnode *n,int l);

int main(){
	Lnode *h1,*h2,*p,*q;
	Lnode *f = NULL;
	int length_1 = 0,length_2 = 0;
	srand((unsigned)time(NULL));	//产生随机数
	h1 = (Lnode *)malloc(sizeof(Lnode));		//创建链表1的头结点
	h1->next = NULL;
	h2 = (Lnode *)malloc(sizeof(Lnode));		//创建链表2的头结点
	h2->next = NULL;
	
	build(h1,rand()%30);  //调用build()创建单链表1
	build(h2,rand()%30);  //调用build()创建单链表2
	
	//判断是否存在交点
	if(h1->next == NULL || h2->next == NULL)
		printf("两个单链表不存在交点!");
	else{
		p = h1->next;
		q = h2->next;
		for(length_1 = 0;p != NULL;length_1++)
			p = p->next;
		for(length_2 = 0;q != NULL;length_2++)
			q = q->next;
		if(length_1 >= length_2)
			f = judge(h1->next,h2->next,length_1-length_2);
		else
			f = judge(h2->next,h1->next,length_2-length_1);
	}

	//释放单链表所占的空间
	if(length_1 <= length_2){
		Free(h1->next,NULL);
		Free(h2->next,f);
	}
	else{
		Free(h2->next,NULL);
		Free(h1->next,f);
	}
	h1->next = NULL;
	h2->next = NULL;
    getch();
	return 0;
}

void Free(Lnode *r,Lnode *t){
	Lnode *b;
	while(r != t){
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

Lnode* judge(Lnode *m,Lnode *n,int l){
	int i;
	for(i = 0;i < l;i++)
		m = m->next;
	while(m != NULL){
		if(m == n){
			printf("交点的地址为:%p",m);
			break;
		}
		m = m->next;
		n = n->next;
	}
	if(m == NULL)
		printf("两个单链表没有交点!");
	return m;
}