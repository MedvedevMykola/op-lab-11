#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>
struct STree
{
	int data;
	STree *right, *left;
}*root;
void create(int, STree*&);
void print(STree*(&),int);
void create(int x, STree *&tree)
{
	if (tree == NULL)
	{
		tree = new STree;
		root = tree;
		tree->data = x;
		root->data = tree->data;
		root->left = root->right = NULL;
		tree->left = NULL, tree->right = NULL;
	}
	
		if (x<tree->data)  
		{
			if (tree->left != NULL) create(x, tree->left);
			else 
			{
				tree->left = new STree;  
				tree->left->left = tree->left->right = NULL;
				tree->left->data = x;
			}
		}

		if (x<tree->data)  
		{
			if (tree->right != NULL) create(x, tree->right);
			else 
			{
				tree->right = new STree;
				tree->right->left = tree->right->right = NULL;
				tree->right->data = x;
			}
		}
}

void print(STree *(&root), int spaces) {
	if (root->right != NULL) print(root->right, spaces + 1);
	for (int i = 0; i<spaces; i++) printf("|");
	printf("%d\n", root->data);
	if (root->left != NULL) print(root->left, spaces + 1);
}
int main()
{
	STree *tree = NULL;
	int n, t, j = 2;
	printf("Enter n:\n");
	scanf_s("%d", &n);
	int *ar = new int[pow(2, n) - 1];
	ar[0] = n;
	ar[1] = n - 1;
	ar[2] = n - 1;
	t = n-1;
	for (int i = 3; i < pow(2, n) - 1; i++) {
		if (i > pow(2, j)-2)
		{
			j += 1;
			t -= 1;
		}
		ar[i] = t;
	}
	for (int i = 0; i < pow(2,n)-1; i++)create(ar[i], tree);
	print(tree,0);
	
	_getch();
	return 0;
}

