#include<stdio.h>
#define maxsize 10
typedef struct node{
	char data;
	struct node *lchild,*rchild;
} node;
typedef node *bitree;
bitree buildtree()
{
    char c;
    node *p;
    c=getchar();
    if(c=='0')
        p=NULL;
    else
    {
           p=new(node);
           p->data=c;
           p->lchild=buildtree();
           p->rchild=buildtree();
    }
    return(p);
}

int calculator(bitree root, int k)
{
	int a, b;
	a=b=0;
        if(!root) return(0);
	if (k == 1)
		return(1);
	if (root->lchild != NULL)
		a=calculator(root->lchild, k - 1);
	if (root->rchild != NULL)
		b=calculator(root->rchild, k - 1);
	return(a+b);
}

int depth(bitree t)//�߶�
{
    if(t==NULL)
        return(0);
    if(t&&t->lchild==NULL&&t->rchild==NULL)
        return(1);
    return(depth(t->lchild)>depth(t->rchild)?depth(t->lchild)+1:depth(t->rchild)+1);
}

int nodnum(bitree t)//�������
{
    if(t==NULL)
        return(0);
    if(t&&t->lchild==NULL&&t->rchild==NULL)
        return(1);
    return(nodnum(t->lchild)+nodnum(t->rchild)+1);
}

int lefnum(bitree t)//Ҷ�ӽ����
{
    if(t==NULL)
        return(0);
    if(t&&t->lchild==NULL&&t->rchild==NULL)
        return(1);
    return(lefnum(t->lchild)+lefnum(t->rchild));
}

int samstruc(bitree t1,bitree t2)
{
    if(!t1&&!t2)
        return(1);
    if(!t2||!t1)
        return(0);
    return(samstruc(t1->lchild,t2->lchild)&&samstruc(t1->rchild,t2->rchild));
}

void main()
{
    bitree t;
    t=buildtree();   //  ����������abc00d00e0fg000
    printf("\n�������ĸ߶�Ϊ��\n");
    printf("%d\n",depth(t));
    printf("\n�������Ľ������Ϊ��\n");
    printf("%d\n",nodnum(t));
    printf("\n��������Ҷ�ӽ����Ϊ��\n");
    printf("%d\n",lefnum(t));
    printf("\n��������K�����Ϊ��\n");
    printf("%d\n",calculator(t, 3));
}
