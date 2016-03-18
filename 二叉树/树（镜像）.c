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
void DLR(bitree root)
{
    if (root!=NULL)
    {   printf("%c",root->data);
            DLR(root->lchild);
            DLR(root->rchild);
    }
}

void LDR(bitree root)
{
    if(root !=NULL)
    {
            LDR(root->lchild);
            printf("%c",root->data);
            LDR(root->rchild);
    }
}

void LRD (bitree root)
{
    if(root !=NULL)
    {
        LRD(root->lchild);
        LRD(root->rchild);
        printf("%c",root->data);
    }
}

void mirror(bitree &t)
{
    bitree p;
    if(t==NULL)
        return;
    if(t&&t->lchild==NULL&&t->rchild==NULL)
        return;
    p=t->lchild;t->lchild=t->rchild;t->rchild=p;
    mirror(t->lchild);
    mirror(t->rchild);
}
int main()
{
    bitree t;
    t=buildtree();//  测试用例：abc00d00e0fg000
    mirror(t);
    printf("镜像前序遍历：\n");
    DLR(t);
    printf("\n镜像中序遍历：\n");
    LDR(t);
    printf("\n镜像后序遍历：\n");
    LRD(t);
    printf("\n");
}
