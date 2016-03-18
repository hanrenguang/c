#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode,*Linklist;

//�ͷ�����Ĵ洢�ռ�
void Free(Lnode *r);

//�β�t���ڴ�ͷ����ֵ��nΪ�����ĵ�����Ľ�����������������
void build(Lnode *t,int n);

int main(){
	Lnode *p,*q;
	Linklist h;
	srand((unsigned)time(NULL));	//���������
	h = (Lnode *)malloc(sizeof(Lnode));		//����ͷ���
	h->next = NULL;
	build(h,rand()%30);  //����build()����������

	//�ҳ��м��㣬�������ַ
	p = h;
	q = h;
	if(h->next == NULL)
		printf("������Ϊ��!");
	else{
		p = p->next;
		q = q->next->next;
		while(q != NULL && q->next != NULL){
			p = p->next;
			q = q->next->next;
		}
		if(q == NULL)
			printf("�м���ĵ�ַ:%p",p);
		else
			printf("��ż�������!");
	}
	//�ͷŵ�������ռ�Ŀռ�
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