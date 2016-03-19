#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *lchild,*rchild;
}node;

typedef node *bitree;
//前序构造二叉树
node *buildtree(){
	bitree p;
	char c;
	c = getchar();
	if(c == '0')
		p = NULL;
	else{
		p = new(node);
		p->data = c;
		p->lchild = buildtree();
		p->rchild = buildtree();
	}
	return p;
}

int searchhigh(node *m){
	int a,b;

	if(m == NULL)
		return 0;
	if(m->lchild != NULL)
		a = 1;
	if(m->rchild != NULL)
		b = 1;
	a += searchhigh(m->lchild);
	b += searchhigh(m->rchild);
	
	return (a>b?a:b);
}

int main(){
	bitree q;
	int high;
	printf("按前序输入:\n");
	q = buildtree();
	high = searchhigh(q);
	printf("二叉树的高度:%d\n",high + 1);
	getchar();
	return 0;
}