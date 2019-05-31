#include "huffmanTree.h"

PNode createHuffmanTree(PNode * a)
{
	PNode tmp;
	int low = 0;
	do
	{
		sort(a, low);
		tmp = malloc(sizeof(Node));
		tmp->weight = a[low]->weight;
		tmp->weight += a[low + 1]->weight;
		tmp->LChild = a[low];
		tmp->RChild = a[++low];
		tmp->value = -1;
		a[low] = tmp;
	} while (a[low + 1]);
	return a[low];
}

void printHuffmanTree(PNode top)
{
	printf("Inorder:");    InorderTraversal(top);    printf("\n");
	printf("Preorder:");   PreorderTraversal(top);   printf("\n");
	printf("Postorder:");  PostorderTraversal(top);  printf("\n");
}

void InorderTraversal(PNode top)
{
	if (top)
	{
		if (top->LChild)
			InorderTraversal(top->LChild);
		if (top->value == -1)
		{
			printf("  %d", top->value);
		}
		else
		{
			printf(" '%c'", top->value);
		}
		if (top->RChild)
			InorderTraversal(top->RChild);
	}
	return;
}

void PreorderTraversal(PNode top)
{
	if (top)
	{
		if (top->value == -1)
		{
			printf(" %d", top->value);
		}
		else
		{
			printf(" '%c'", top->value);
		}
		if (top->LChild)
			PreorderTraversal(top->LChild);
		if (top->RChild)
			PreorderTraversal(top->RChild);
	}
	return;
}

void PostorderTraversal(PNode top)
{
	if (top)
	{
		if (top->LChild)
			PostorderTraversal(top->LChild);
		if (top->RChild)
			PostorderTraversal(top->RChild);
		if (top->value == -1)
		{
			printf(" %d", top->value);
		}
		else
		{
			printf(" '%c'", top->value);
		}
	}
	return;
}

int* huffmanCoding(PNode top)
{
	
}