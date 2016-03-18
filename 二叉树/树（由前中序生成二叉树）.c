#include<stdio.h>
#define maxsize 100
typedef struct node{
char data;
struct node *lchild,*rchild;
} node;
typedef node *bitree;
typedef struct {
    bitree a[maxsize];
    int top;
}seqstack;
typedef struct {
    char ch[maxsize];
    int low,high;
}seqlist;
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

bitree buildtreebyseq(seqlist s1,seqlist s2)
{
    int rt,j,l1,l2,h1,h2;
    l1=s1.low;l2=s2.low;h1=s1.high;h2=s2.high;
    char c; node *p;
    if(s1.low>s1.high||s2.low>s2.high)
        return(0);
    c=s1.ch[s1.low];
    p=new(node);
    p->data=c;
    for(j=s2.low;j<=s2.high;j++)
        if(c==s2.ch[j]) { rt=j; break;}
    s1.low=l1+1;     s1.high=l1+rt-l2;
    s2.low=l2;       s2.high=rt-1;
    p->lchild=buildtreebyseq(s1,s2);
    s1.low=l1+rt-l2+1;   s1.high=h1;
    s2.low=rt+1;         s2.high=h2;
    p->rchild=buildtreebyseq(s1,s2);
    return(p);
}

void preorder(bitree t,seqlist &spreoder)
{
    spreoder.low=0;
    int i=0;
    seqstack s;
    s.top = -1;//置栈空
    while((t)||(s.top!=-1))
    {
        while(t)
        {
            printf("%c", t->data);
            spreoder.ch[i]=t->data;
            i++;
            s.top++;
            s.a[s.top] = t;
            t = t->lchild;
        }
        if (s.top>-1) {
            t = s.a[s.top];
            s.top--;
            t = t->rchild;
        }
    }
    spreoder.high=i-1;
}

void DLR( node *root )
{
    if (root!=NULL) //非空二叉树
    {   printf("%c",root->data); //访问D
            DLR(root->lchild); //递归遍历左子树
            DLR(root->rchild); //递归遍历右子树
    }
}

void midorder(bitree t,seqlist &smidoder)
{
    smidoder.low=0;
    int i=0;
    seqstack s;
    s.top = -1;//置栈空
    while((t)||(s.top!=-1))
    {
        while(t)
        {
            s.top++;
            s.a[s.top] = t;
            t = t->lchild;
        }
        t=s.a[s.top];
        smidoder.ch[i]=t->data;
        i++;
        printf("%c", t->data);
        s.top--;
        t=t->rchild;
    }
    smidoder.high=i-1;
}

void LDR(node *root)
{
    if(root !=NULL)
    {
            LDR(root->lchild);
            printf("%c",root->data);
            LDR(root->rchild);
    }
}

void postorder(bitree t)//这是非递归后序实现
{
    bitree lastvist;
    seqstack s;
    lastvist=0;
    s.top = -1;//置栈空
    while(t||s.top != -1)
    {
       while(t)
        {
            s.top++;
            s.a[s.top]=t;
            t=t->lchild;
        }
        t=s.a[s.top];
        if(t->rchild==lastvist||t->rchild==NULL)
        {
            printf("%c", t->data);
            s.top--;
            lastvist=t;
            t=0;
        }
        else t=t->rchild;
    }
}

void LRD (node *root)
{
    if(root !=NULL)
    {
        LRD(root->lchild);
        LRD(root->rchild);
        printf("%c",root->data);
    }
}

int main()
{
    seqlist s1,s2;
    bitree t1,t2;
    t1=buildtree();   //  测试用例：abc00d00e0fg000
    printf("\n第一次生成的二叉树非递归前序遍历，并生成前序序列s1：\n");
    preorder(t1,s1);
    printf("\n第一次生成的二叉树非递归中序遍历，并生成中序序列s2：\n");
    midorder(t1,s2);
    t2=buildtreebyseq(s1,s2);
    printf("\n第二次生成的二叉树前序遍历：\n");
    DLR(t2);
    printf("\n第二次生成的二叉树中序遍历：\n");
    LDR(t2);
}
