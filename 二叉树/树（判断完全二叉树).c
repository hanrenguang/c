#include<stdio.h>
#define maxsize 100
typedef struct node{
char data;
struct node *lchild,*rchild;
} node;
typedef node *bitree;
typedef struct {
    bitree a[maxsize];
    int first,last;
}sequeue;
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

int IsComplete(bitree t)
//依照层次遍历将结点法如数组中，检查角标的2倍关系
{
    sequeue s;
    if(!t) return(1);
    s.a[1]=t;
    s.first=1;
    s.last=2;
    while(s.first!=s.last)
    {
        t=s.a[s.first];
        if(t->lchild)
        {
            s.a[s.last]=t->lchild;
            if(s.first+s.first!=s.last)return(0);
            s.last++;
        }
        if(t->rchild)
        {
            s.a[s.last]=t->rchild;
            if(s.first+s.first+1!=s.last)return(0);
            s.last++;
        }
        s.first++;
    }
    return(1);
}

int main()
{
    bitree t;
    t=buildtree();//  测试用例：abc00d00e0fg000   测试用例2：abdh00i00e00cf00g00
    printf("\n");
    if(IsComplete(t))
        printf("\nIt is complete\n");
    else
        printf("\nIt is not complete\n");
}
