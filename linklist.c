#include <stdio.h>

typedef struct node{
	char data;
	struct node *next;
}node;

void build(node *q);

void myFree(node *r);

int main(int argc, char const *argv[])
{
	int n, i;
	node *p;
	node *h = (node *)malloc(sizeof(node));
	h->next = NULL;
	p = h;

	scanf("%d",&n);
    
    getchar();

	for(i = 0; i < n; i++)
	{
		build(p);
		p = p->next;
	}
	getchar();

	if(h->next != NULL)
		myFree(h->next);

	h->next = NULL;

	return 0;
}

void build(node *q)
{
	q->next = (node *)malloc(sizeof(node));
	q = q->next;
	q->data = getchar();
	q->next = NULL;
}

void myFree(node *r)
{
	node *m;
	m = r->next;

	while(r)
	{
		free(r);
		if(!m)
		{
			r = m;
			m = m->next;
		}
		else
			r = NULL;
	}
}
