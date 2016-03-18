#include<stdio.h>
#define maxsize 10
typedef struct node{
char data;
struct node *lchild,*rchild;
}node;
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
    int i,level,width;
    int ct[maxsize];
    int num[maxsize];
    for(i=0;i<maxsize;i++)
    {
        ct[i]=num[i]=0;
    }
    if(!t)
    {
        printf("\n empty tree!\n");
        return(1);
    }
    q.first=q.tail=0; //置队空
    ct[0]=num[0]=0;
    ct[1]=num[1]=1;
    level=2;
    while(1)
    {
        printf("%c", t->data);
        if(t->lchild)
            {enqueue(q,t->lchild);num[level]=num[level]+1;}
        if(t->rchild)
            {enqueue(q,t->rchild);num[level]=num[level]+1;}
        ct[level]=num[level];
        if(q.first!=q.tail) //队不空
        {
            t=q.a[q.first];   //出队
            q.first=(q.first+1)%maxsize;
            ct[level-1]--;
            if(ct[level-1]<=0)
            level++;
        }
        else
            {
                printf("\n levorder visit successfully!\n");
                break;
            }
    }
    printf("\n 共有%d层（树的高度）\n",level-1);
    width=0;
    for(i=1;i<level;i++)
    {
        if(width<num[i]) width=num[i];
        printf(" 第%d层:  有%d个    \n",i,num[i]);
    }
    printf(" 树的宽度为： %d   \n",width);
    return(1);
}

int DLR( node *root )
{
    if (root!=NULL) //非空二叉树
    {   printf("%c",root->data); //访问D
            DLR(root->lchild); //递归遍历左子树
            DLR(root->rchild); //递归遍历右子树
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
    t=buildtree();//  测试用例：abc00d00e0fg000   maxsize最小值为4
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
