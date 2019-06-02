#include "huffmanTree.h"

/*****************************************************************
*Function:createHuffmanTree
*Description:创建哈弗曼树
*Calls:None
*Called By:encode
*Input:PNode
*Output:None
*Return:PNode
*Others:None
*****************************************************************/
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

/*****************************************************************
*Function:printHuffmanTree
*Description:打印哈弗曼树
*Calls:InorderTraversal, PreorderTraversal, PostorderTraversal, printf
*Called By:encode
*Input:PNode
*Output:打印哈弗曼树
*Return:void
*Others:None
*****************************************************************/
void printHuffmanTree(PNode top)
{
	printf("Inorder:");    InorderTraversal(top);    printf("\n");
	printf("Preorder:");   PreorderTraversal(top);   printf("\n");
	printf("Postorder:");  PostorderTraversal(top);  printf("\n\n");
}

/*****************************************************************
*Function:InorderTraversal
*Description:中序遍历哈弗曼树
*Calls:InorderTraversal
*Called By:printHuffmanTree
*Input:PNode
*Output:中序遍历哈弗曼树
*Return:void
*Others:None
*****************************************************************/
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

/*****************************************************************
*Function:PreorderTraversal
*Description:先序遍历哈弗曼树
*Calls:PreorderTraversal
*Called By:printHuffmanTree
*Input:PNode
*Output:先序遍历哈弗曼树
*Return:void
*Others:None
*****************************************************************/
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

/*****************************************************************
*Function:PostorderTraversal
*Description:后序遍历哈弗曼树
*Calls:PreorderTraversal
*Called By:printHuffmanTree
*Input:PNode
*Output:后序遍历哈弗曼树
*Return:void
*Others:None
*****************************************************************/
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

/*****************************************************************
*Function:createHuffmanCoding
*Description:创建哈夫曼编码
*Calls:printf， createHuffmanCoding
*Called By:encode
*Input:PNode, Contents*, int*, int
*Output:每个字符的哈夫曼编码
*Return:void
*Others:None
*****************************************************************/
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