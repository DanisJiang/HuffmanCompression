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
	printf("Inorder:");    InorderTraversal(top);    printf("\n\n");
	printf("Preorder:");   PreorderTraversal(top);   printf("\n\n");
	printf("Postorder:");  PostorderTraversal(top);  printf("\n\n");
}

void InorderTraversal(PNode top)
{
	if (top)
	{
		if (top->LChild)
			InorderTraversal(top->LChild);
		if (top->value == -1)
		{
			printf(",N(%d)", top->weight);
		}
		else
		{
			printf(",'0x%x'", top->value);
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
			printf(",N(%d)", top->weight);
		}
		else
		{
			printf(",'0x%x'", top->value);
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
			printf(",N(%d)", top->weight);
		}
		else
		{
			printf(",'0x%x'", top->value);
		}
	}
	return;
}

void createHuffmanCoding(PNode top, Contents* content,int* code ,int n)
{
	if (top)
	{
		if (top->value != -1)
		{
			printf("'0x%x': ", top->value);
			content->huffmanCode[top->value][0] = n;
			for (int i = 0; i < n; i++)
			{
				content->huffmanCode[top->value][i+1] = code[i];
				printf("%d", code[i]);
			}
		}
		if (top->LChild)
		{
			code[n] = 0;
			createHuffmanCoding(top->LChild, content, code, n + 1);
		}
		if (top->RChild)
		{
			code[n] = 1;
			createHuffmanCoding(top->RChild, content, code, n + 1);
		}
	}
	return;
}