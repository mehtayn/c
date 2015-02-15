// mehtayn.com
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node *BTREE;
BTREE new_node(int key)
{
	BTREE p;
	p=(BTREE)malloc(sizeof(struct node));
	p->data=key;
	p->left=NULL;
	p->right=NULL;
	return p;
}
BTREE insert(BTREE root, int data)
{
	if(root!=NULL)
	{
		if(data<root->data)
			root->left=insert(root->left,data);
		else
			root->right=insert(root->right,data);
	}
	else
	{
		root=new_node(data);
	}
	return root;
}
void inorder(BTREE root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%2.d ",root->data);
		inorder(root->right);
	}
}
void preorder(BTREE root)
{
	if(root!=NULL)
	{
		printf("%2.d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(BTREE root)
{
	if(root!=NULL)
	{	
		postorder(root->left);
		postorder(root->right);
		printf("%2.d ",root->data);
	}
}
int size(BTREE root)
{
	if(root!=NULL)
		return size(root->left)+1+size(root->right);
	else
		return 0;
}
int height(BTREE root)
{
	int lheight,rheight;
	if(root==NULL)
		return 0;
	else
	{
		lheight=height(root->left);
		rheight=height(root->right);
		if(lheight>rheight)
			return lheight+1;
		else
			return rheight+1;
	}	
}
BTREE search(BTREE root,int key)
{
	if(root==NULL)
		return 0;
	else
	{
		if(key<root->data)
		{
			//node=search(root->left,key);
			return search(root->left,key);
		}	
		else if(key>root->data)
		{
			//node=search(root->right,key);
			return search(root->right,key);
		}	
		else
			return root; 
	}
}
BTREE delete_node(BTREE root,int key)
{
	BTREE p,q;
	if(root==NULL)
		return NULL;
	if(root->data==key)
	{
		if(root->left==root->right)
		{
			free(root);
			return NULL;
		}
		else
		{
			if(root->left==NULL)
			{
				p=root->right;
				free(root);
				return p;
			}
			else if(root->right==NULL)
			{
				p=root->left;
				free(root);
				return p;
			}
			else
			{
				p=q=root->right;
				while(p->left!=NULL)
					p=p->left;
				p->left=root->left;
				free(root);
				return q;
			}
		}
	}
	if(root->data < key)
	{
		root->right=delete_node(root->right,key);
	}
	else
	{
		root->left=delete_node(root->left,key);
	}
	return root;
	
}
int min(BTREE root)
{
	if(root==NULL) return 0;
	while(root->left!=NULL)
		root=root->left;
	return root->data;
}
int max(BTREE root)
{
	if(root==NULL) return 0;
	while(root->right!=NULL)
		root=root->right;
	return root->data;
}
void mirror(BTREE root)
{
	if(root==NULL)
		return ;
	BTREE temp;
	mirror(root->left);
	mirror(root->right);
	temp=root->left;
	root->left=root->right;
	root->right=temp;
}
int path(BTREE root,int sum)
{
	if(root==NULL)
		return(sum==0);
	int pathSum=sum-root->data;
	return(path(root->left,pathSum) || path(root->right,pathSum));
}
int isBST(BTREE root)
{
	if(root==NULL)
		return true;
	if(root->left!=NULL && max(root->left) > (root->data))
		return false;
	if(root->right!=NULL && max(root->right) <= root->data)
		return false;
	if(!isBST(root->left) || !isBST(root->right))
		return false;
	return true;
}
int sumLeaves(BTREE root)
{
	if(root!=NULL)
	{
		if(root->left==root->right)
			return root->data;
		else
			return sumLeaves(root->right)+sumLeaves(root->left);
	}
}
BTREE copyOdd(BTREE root,BTREE copy)
{
	if( root != NULL)
	{
		if( root -> data %2 !=0)
			copy=insert(copy,root->data);
		copyOdd(root->left,copy);
		copyOdd(root->right,copy);
	}
	return copy;
}
int isSame(BTREE a,BTREE b)
{
	if(a==NULL && b==NULL)
		return 1;
	else if(a!=NULL & b==NULL)
		return((a->data==b->data) && isSame(a->left,b->left) && isSame(a->right,b->right));
	else
		return 0;
}
int main()
{
	BTREE root,copy;
	copy=new_node(0);
	int dizi[7]={10,5,12,2,7,11,13};
	for (int i = 0; i < 7; i++)
	{
		root=insert(root,dizi[i]);
	}
	printf("Preorder :");
	preorder(root);
	printf("\nPostOrder:");
	postorder(root);
	printf("\ninOrder  :");
	inorder(root);
	printf("\nSize: %d",size(root));
	printf("\nHeight: %d",height(root));
	printf("\nEn Kucuk Eleman: %d \nEn Buyuk Eleman: %d",min(root),max(root));
	root=delete_node(root,5);
	printf("\nSilinmis Hali preorder : ");
	preorder(root);
	printf("\nBinary Search Tree mi? %d",isBST(root));
	printf("\nYol var mi? %d",path(root,33));
	printf("\nCocuklarin Yerleri degisince preorder: ");
	mirror(root);
	preorder(root);
	printf("\nYapraklarin toplami: %d",sumLeaves(root));
	printf("\nTek: ");
	copyOdd(root,copy);
	inorder(copy);
	printf("\nAgaclar ayni mi? %d",isSame(root,copy));
	getch();
}
