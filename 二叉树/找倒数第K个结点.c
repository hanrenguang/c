#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode;
//�ͷ�����Ĵ洢�ռ�
void Free(Lnode *r);
//�β�t���ڴ�ͷ����ֵ��nΪ�����ĵ�����Ľ�����������������
void build(Lnode *t,int n);

int main(){
	Lnode *h,*p,*q;
	int length,k,i;
	scanf("%d",&k);  //����Ҫ�ҵĵ����ڼ������
	srand((unsigned)time(NULL));	//���������
	h = (Lnode *)malloc(sizeof(Lnode));		//����ͷ���
	h->next = NULL;
	length = rand()%30;
	build(h,length);  //����build()����������

	//�ҳ�������K�����
	p = h->next;
	q = h->next;
	if(length < k)
		printf("������ĳ���С��k!");
	else{
		for(i = 0;i < k;i++)
			p = p->next;
		while(p != NULL){
			p = p->next;
			q = q->next;
		}
		printf("������k������ֵ�͵�ַΪ:%d\t%p",q->data,q);
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
	while(n){
		t->next = (Lnode*)malloc(sizeof(Lnode));
		t = t->next;
		t->data = rand() % 20;
		t->next = NULL;
		n--;
	}
}