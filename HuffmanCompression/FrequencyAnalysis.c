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
*Calls:
*Called By:encode
*Input:Content*
*Output:NULL
*Return:PNode
*Others:NULL
*****************************************************************/
PNode* intArray2PNodeArray(Contents* content)
{
	PNode* a = malloc(0);
	int n = -1;
	for (int i = 0; i < 128; i++)
	{
		if (content->frequency[i])
		{
			a = realloc(a, sizeof(PNode));
			a[++n] = malloc(sizeof(Node));
			a[n]->value = i;
			a[n]->weight = content->frequency[i];
		}
	}
	a = realloc(a, sizeof(PNode));
	a[++n] = NULL;  // PNode结尾指示符
	return a;
}

/*****************************************************************
*Function:sort
*Description:按照权值从小到大排序
*Calls:
*Called By:encode
*Input:PNode
*Output:NULL
*Return:PNode*
*Others:NULL
*****************************************************************/
PNode* sort(PNode* a)
{

}