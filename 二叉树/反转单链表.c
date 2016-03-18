#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Lnode{

	int data;

	struct Lnode *next;

}Lnode;

//�ͷ�����Ĵ洢�ռ�
void Free(Lnode *r);

//�β�t���ڴ�ͷ����ֵ��nΪ�����ĵ�����Ľ�����������������
void Build(Lnode *t,int n);

//��ӡ��ַ����֤�Ƿ�ת
void Print(Lnode *m);



int main(){

	Lnode *h,*p,*q,*r;

	srand((unsigned)time(NULL));	//���������

	h = (Lnode *)malloc(sizeof(Lnode));		//����ͷ���

	h->next = NULL;

	Build(h,rand()%30);  //����build()����������

	
	printf("��ת֮ǰ��������ĵ�ַ����Ϊ:\n");

	Print(h->next);  //��ӡ��ת֮ǰ������ĵ�ַ

	
	//ʵ�ֵ�����ķ�ת

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


	printf("��ת֮��������ĵ�ַ����Ϊ:\n");

	Print(h->next);    //��ӡ��ת��ĵ�����ĵ�ַ

	
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

		printf("������Ϊ��!");

	else{

		while(m){

			printf("%p\t",m);

			m = m->next;

		}

	}

	printf("\n");

}