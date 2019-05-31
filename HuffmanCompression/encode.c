#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encode.h"
#include "FrequencyAnalysis.h"
#include "HuffmanTree.h"


/*****************************************************************
*Function:encode
*Description:编码模块
*Calls:readFile, frequency
*Called By:main
*Input:argv[]
*Output:NULL
*Return:void
*Others:NULL
*****************************************************************/
void encode(char *argv[])
{
	FILE* inputFp;
	errno_t err;
	if (err = fopen_s(&inputFp, argv[2],"rb"))
	{
		printf("error: no such file\n");
		exit(0);
	}
	else
	{
		printf("success to open %s\n\n", argv[2]);
	}
	Contents *content;
	if(!(content = readFile(inputFp)))
	{
		printf("error: failed to read file\n");
		fclose(inputFp);
		exit(0);
	}
	frequency(content);
	/*for (int i = 0; i < 128; i++)
	{
		if (content->frequency[i])
		{
			printf("\"%c\": %d ", i, content->frequency[i]);
		}
	}*/
	PNode* PNodeArray = intArray2PNodeArray(content);
	createHuffmanTree(PNodeArray);
	int i = 0;
	while (PNodeArray[i])
	{
		if (i % 4 == 0)
		{
			printf("\n");
		}
		printf("\" %c \": %d   ", PNodeArray[i]->value, PNodeArray[i]->weight);
		i++;
	}
}

/*****************************************************************
*Function:readFile
*Description:获得文本的长度并读取到Contents结构体中
*Calls:fseek, flen, rewind, malloc, sizeof
*Called By:encode
*Input:fp
*Output:None
*Return:Contents*
*Others:None
*****************************************************************/
Contents* readFile(FILE *fp)
{
	int flen;
	fseek(fp, 0L, SEEK_END);
	flen = ftell(fp);
	rewind(fp);
	char *s = malloc(flen);
	if (!s)
	{
		fclose(fp);
		exit(0);
	}
	fread(s, sizeof(char), flen / sizeof(char), fp);
	Contents* content = (Contents*)malloc(sizeof(Contents));
	content->size = flen / sizeof(char);
	content->pt = s;
	return content;
}