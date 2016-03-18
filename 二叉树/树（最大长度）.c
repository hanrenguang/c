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

int depth(bitree t)
{
    if(t==NULL)
        return(0);
    if(t&&t->lchild==NULL&&t->rchild==NULL)
        return(1);
    return(depth(t->lchild)>depth(t->rchild)?depth(t->lchild)+1:depth(t->rchild)+1);
}

int maxdistance(bitree t)//�������
{
    int d0,d1,d2;
    bitree t1,t2;
    if(!t) return(0);
    d0=depth(t->lchild)+depth(t->rchild);
    t1=t->lchild;
    t2=t->rchild;
    d1=d2=0;
    if(!t1)
    d1=depth(t1->lchild)+depth(t1->rchild);
    if(!t2)
    d2=depth(t2->lchild)+depth(t2->rchild);
    if(d1>d0&&d1>d2) return(d1);
    if(d2>d0&&d2>d1) return(d2);
    return(d0);
}


int maxdist(bitree t)
{
    int d0,d1,d2;
    bitree t1,t2;
    if(!t) return(0);
    d0=depth(t->lchild)+depth(t->rchild);
    d1=maxdist(t->lchild);
    d2=maxdist(t->rchild);
    if(d1>d0&&d1>d2) return(d1);
    if(d2>d0&&d2>d1) return(d2);
    return(d0);
}

int main()
{
    bitree t,q;
    t=buildtree();   //  ����������abd00efhjl00000g0i0k0m00c00  ��󳤶�ʵ��Ϊ��8
    printf("\n�������ĸ߶�Ϊ��\n");
    printf("%d\n",depth(t));
    printf("\n����������󳤶�������Ϊ��\n");
    printf("%d\n",maxdistance(t));
    printf("\n����������󳤶�ʵ��Ϊ��\n");
    printf("%d\n",maxdist(t));
}
