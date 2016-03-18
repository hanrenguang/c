#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 3

typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode;
//�β�t���ڴ�ͷ����ֵ��nΪ�����ĵ�����Ľ�����������������
Lnode* build(Lnode *t,int n);

int main(){
	Lnode *h,*p,*q,*last;
	int i,length;
	srand((unsigned)time(NULL));	//���������
	h = (Lnode *)malloc(sizeof(Lnode));		//����ͷ���
	h->next = NULL;
	length = rand()%30;
	last = build(h,length);  //����build()����������
	last->next = h->next;  //����������ѭ������
	p = h->next;

	if(h->next == NULL)
		printf("����Ϊ��!");
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