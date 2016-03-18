#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <time.h>

typedef struct Lnode{

	int data;

	struct Lnode *next;

}Lnode;

//�ͷ�����Ĵ洢�ռ�

void Free(Lnode *r,Lnode *t);
//�β�t���ڴ�ͷ����ֵ��nΪ�����ĵ�����Ľ�����������������
void build(Lnode *t,int n);
//�жϲ��������,���Ƚϳ��ĵ�������m���̵Ĵ���n��lΪ���߳��Ȳ�ľ���ֵ
Lnode* judge(Lnode *m,Lnode *n,int l);

int main(){
	Lnode *h1,*h2,*p,*q;
	Lnode *f = NULL;
	int length_1 = 0,length_2 = 0;
	srand((unsigned)time(NULL));	//���������
	h1 = (Lnode *)malloc(sizeof(Lnode));		//��������1��ͷ���
	h1->next = NULL;
	h2 = (Lnode *)malloc(sizeof(Lnode));		//��������2��ͷ���
	h2->next = NULL;
	
	build(h1,rand()%30);  //����build()����������1
	build(h2,rand()%30);  //����build()����������2
	
	//�ж��Ƿ���ڽ���
	if(h1->next == NULL || h2->next == NULL)
		printf("�������������ڽ���!");
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

	//�ͷŵ�������ռ�Ŀռ�
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
			printf("����ĵ�ַΪ:%p",m);
			break;
		}
		m = m->next;
		n = n->next;
	}
	if(m == NULL)
		printf("����������û�н���!");
	return m;
}