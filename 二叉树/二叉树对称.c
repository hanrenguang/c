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

	if((c = getchar()) == '0')
	{
		p = NULL;
	}
	else
	{
		p = (node *)malloc(sizeof(node));
		p->data = c;
		p->lchild = buildtree();
		p->rchild = buildtree();
	}
	return p;
}
//对称二叉树
void symmetry(node *p){
	node *t = NULL;
	if(!p)
		return ;
	t = p->lchild;
	p->lchild = p->rchild;
	p->rchild = t;
	symmetry(p->lchild);
	symmetry(p->rchild);
}
//前序
int DLR(node *root)
{
    if (root!=NULL) //非空二叉树
    {   
		printf("%c",root->data); //访问D
        DLR(root->lchild); //递归遍历左子树
        DLR(root->rchild); //递归遍历右子树
    }
    return 0;
}

void freeTree(bitree p)
{
	if(p!=NULL){
		freeTree(p->lchild);
		freeTree(p->rchild);
		free(p);
	}
	return ;
}

int main(){
	bitree q;
	printf("按前序输入:\n");
	q = buildtree();
	symmetry(q);
	printf("对称后前序输出:\n");
	DLR(q);
	freeTree(q);
	getchar();
	return 0;
}