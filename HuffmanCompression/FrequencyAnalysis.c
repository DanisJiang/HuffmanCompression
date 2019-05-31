#include<stdlib.h>
#include "FrequencyAnalysis.h"
/*****************************************************************
*Function:frequency
*Description:统计每个字符出现次数
*Calls:
*Called By:encode
*Input:Content*
*Output:NULL
*Return:void
*Others:NULL
*****************************************************************/
void frequency(Contents* content)
{
	content->frequency = malloc(sizeof(int) * 128);
	for (int i = 0; i < 128; i++)
	{
		content->frequency[i] = 0;
	}
	for (int i = 0; i < content->size; i++)
	{
		content->frequency[content->pt[i]] += 1;
	}
}

/*****************************************************************
*Function:intArray2PNodeArray
*Description:将每个出现的字符构造成结点，方便后面排序及生成哈夫曼树
*Calls:malloc, realloc
*Called By:encode
*Input:Content*
*Output:NULL
*Return:PNode
*Others:NULL
*****************************************************************/
PNode* intArray2PNodeArray(Contents* content)
{
	PNode* a = malloc(0);
	PNode* new_a;
	int n = -1;
	for (int i = 0; i < 128; i++)
	{
		if (content->frequency[i])
		{
			n++;
			new_a = realloc(a, sizeof(PNode) * (n + 1));
			if (!new_a)
			{
				printf("Error: realloc failed.\n");
				free(a);
			}
			a = new_a;
			a[n] = malloc(sizeof(Node));
			a[n]->value = i;
			a[n]->weight = content->frequency[i];
			a[n]->LChild = NULL;
			a[n]->RChild = NULL;
		}
	}
	new_a = realloc(a, sizeof(PNode) * (n + 1));
	if (!new_a)
	{
		printf("Error: realloc failed.\n");
		free(a);
	}
	a = new_a;
	a[++n] = NULL;  // PNode结尾指示符
	return a;
}

/*****************************************************************
*Function:sort
*Description:按照权值从小到大排序
*Calls:NULL
*Called By:encode
*Input:PNode*, int
*Output:NULL
*Return:void
*Others:NULL
*****************************************************************/
void sort(PNode* a, int i)
{
	int j = 0;
	int min;
	PNode tmp;
	while (a[i])
	{
		j = i + 1;
		min = a[i]->weight;
		while (a[j])
		{
			if (a[j]->weight < a[i]->weight)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp	;
			}
			j++;
		}
		i++;
	}
	return a;
}