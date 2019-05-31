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
		tmp->weight += a[low]->weight;
		tmp->LChild = a[low];
		tmp->RChild = a[++low];
		tmp->value = -1;
		a[low] = tmp;
	} while (a[low + 1]);
	return a[low];
}

int* huffmanCoding(PNode top)
{
	
}