#include "stdafx.h"
#include "TREE.h"
STree*root = NULL;
void create(int x, STree *&tree)
{
	if (tree == NULL)
	{
		tree = new STree;
		root = tree;
		tree->data = x;
		root->data = tree->data;		
		tree->left = NULL, tree->right = NULL;
		root->left = tree->left, root->right = tree->right;
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