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
    q.first=q.tail=0; //�öӿ�
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
        if(q.first!=q.tail) //�Ӳ���
        {
            t=q.a[q.first];   //����
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
    printf("\n ����%d�㣨���ĸ߶ȣ�\n",level-1);
    width=0;
    for(i=1;i<level;i++)
    {
        if(width<num[i]) width=num[i];
        printf(" ��%d��:  ��%d��    \n",i,num[i]);
    }
    printf(" ���Ŀ��Ϊ�� %d   \n",width);
    return(1);
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
