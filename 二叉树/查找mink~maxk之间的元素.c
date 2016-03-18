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
//�ͷ�����Ĵ洢�ռ�
void Free(Lnode *r);
//�β�t���ڴ�ͷ����ֵ��nΪ�����ĵ�����Ľ�����������������
void build(Lnode *t,int n);

int main(){
	Lnode *h,*p;
	srand((unsigned)time(NULL));	//���������
	h = (Lnode *)malloc(sizeof(Lnode));		//����ͷ���
	h->next = NULL;
	build(h,rand()%30);  //����build()����������

	//�ҵ�mink~maxk֮���Ԫ��
	p = h->next;
	while(p != NULL){
		if(p->data > MINK && p->data < MAXK)
			printf("��ַ:%p ֵ:%d\t",p,p->data);
		p = p->next;
	}

	//�ͷŵ�������ռ�Ŀռ�
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