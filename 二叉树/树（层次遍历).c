#include<stdio.h>
#define maxsize 10
typedef struct node{
	char data;
	struct node *lchild,*rchild;
} node;
typedef node *bitree;
typedef struct {
    bitree a[maxsize];
    int first,tail;
}sequeue;
int enqueue(sequeue &q,bitree t)
{
    if(q.first==(q.tail+1)%maxsize)
    {
        printf("\nqueue overflow!\n");
        return(0);
    }
    q.a[q.tail]=t;
    q.tail=(q.tail+1)%maxsize;
    return(1);
}
bitree buildtree()
{
    char c;
    node *p;
    c=getchar();
    if(c=='0')
    {
        p=NULL;
    }
    else
    {
           p=new(node);
           p->data=c;
           p->lchild=buildtree();
           p->rchild=buildtree();
    }
    return(p);
}

int levorder(bitree t)
{
    sequeue q;
    if(!t)
    {
        printf("\n empty tree!\n");
        return(1);
    }
    q.first=q.tail=0; //�öӿ�
    while(1)
    {
        printf("%c", t->data);
        if(t->lchild)
            enqueue(q,t->lchild);
        if(t->rchild)
            enqueue(q,t->rchild);
        if(q.first!=q.tail)
        {
            t=q.a[q.first];   //����
            q.first=(q.first+1)%maxsize;
        }
        else
            {
                printf("\n levorder visit successfully!\n");
                return(1);
            }
    }
}

int DLR( node *root )
{
    if (root!=NULL) //�ǿն�����
    {   printf("%c",root->data); //����D
            DLR(root->lchild); //�ݹ����������
            DLR(root->rchild); //�ݹ����������
    }
    return(0);
}
int LDR(node *root)
{
    if(root !=NULL)
    {
            LDR(root->lchild);
            printf("%c",root->data);
            LDR(root->rchild);
    }
    return(0);
}

int LRD (node *root)
{
    if(root !=NULL)
    {
        LRD(root->lchild);
        LRD(root->rchild);
        printf("%c",root->data);
    }
    return(0);
}

int main()
{
    bitree t;
    t=buildtree();//  ����������abc00d00e0fg000   maxsize��СֵΪ4
    printf("\n");
    DLR(t);
    printf("\n");
    LDR(t);
    printf("\n");
    LRD(t);
    printf("\n");
    levorder(t);
    printf("\n");
}
