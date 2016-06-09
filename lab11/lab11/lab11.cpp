#include "stdafx.h"
#include "TREE.h"

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

