#include<stdio.h>
#define maxsize 10
typedef struct node{
char data;
struct node *lchild,*rchild;
int ltag,rtag;//���ĳɵ�����
} node;
typedef node *bitree;
typedef struct {
    bitree a[maxsize];
    int top;
}seqstack;

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
           p->ltag=0;
           p->rtag=0;//���ĳɵ�����
           p->data=c;
           p->lchild=buildtree();
           p->rchild=buildtree();
    }
    return(p);
}
bitree threat_tree_by_midorder(bitree t)
{
    bitree tt,pre;
    tt=new(node);
    tt->data='#';
    tt->ltag=tt->rtag=0;//���ĳɵ�����
    tt->rchild=tt;
    tt->lchild=t;
    pre=tt;
    seqstack s;
    s.top = -1;//��ջ��
    while((t)||(s.top!=-1))
    {
        while(t)
        {
            s.top++;
            s.a[s.top] = t;
            if(t->ltag==0){
                t = t->lchild;}
            else t=NULL;
        }
        t=s.a[s.top];
        printf("%c", t->data);
        s.top--;
        if(t->ltag==0&&t->lchild==NULL){t->ltag=1;t->lchild=pre;}
        if(pre->rtag==0&&pre->rchild==NULL){pre->rtag=1;pre->rchild=t;}
        pre=t;
        if(t->rtag==0){
            t = t->rchild;}
        else t=NULL;
    }
    if(pre->rtag==0&&pre->rchild==NULL){pre->rtag=1;pre->rchild=tt;}
    return(tt);
}

int midorder_threatedtree(bitree t)
{
    bitree p;
    p=t->lchild;
    if(p==NULL) return(1);
    while(p!=t)
    {
        while(p->ltag!=1)
            p=p->lchild;
        printf("%c", p->data);
        if(p->rtag==1&&p->rchild!=t)
        {
            p=p->rchild;
            printf("%c", p->data);
        }
        p=p->rchild;
    }
    return (1);
}

int main()
{
    bitree t,tt;
    t=buildtree();   //  ����������abc00d00e0fg000
    printf("\n�ǵݹ����������������\n");
    tt=threat_tree_by_midorder(t);
    printf("\n�������������\n");
    midorder_threatedtree(tt);
    printf("\n");
}
