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
*Output:哈夫曼编码
*Return:void
*Others:NULL
*****************************************************************/
void encode(char *argv[])
{
	FILE* inputFp;
	errno_t err;
	if (err = fopen_s(&inputFp, argv[2],"rb"))
	{
		printf("[*]Error: no such file\n");
		error();
	}
	else
	{
		printf("[*]Success to open %s\n", argv[2]);
	}
	Contents *content;
	if(!(content = readFile(inputFp)))
	{
		printf("[*]Error: failed to read file\n");
		fclose(inputFp);
		error();
	}
	fclose(inputFp);
	printf("[*]Close the file\n\n");
	printf("[*]Contents:\n");
	puts(content->pt);
	printf("\n");
	printf("[*]Frequency:\n");
	frequency(content);
	PNode* PNodeArray = intArray2PNodeArray(content);
	int i = 0;
	while (PNodeArray[i])
	{
		printf("\" 0x%x \": %d   ", PNodeArray[i]->value, PNodeArray[i]->weight);
		i++;
	}
	printf("\n\n");
	PNode top = createHuffmanTree(PNodeArray);
	printf("[*]PrintTree:\n");
	printHuffmanTree(top);
	printf("[*]HuffmanCode:\n");
	int code[10];
	createHuffmanCoding(top, content, code, 0);
	printf("\n\n");
	printf("[*]Output:\n");
	for (int i = 0; i < content->size; i++)
	{
		for (int j = 0; j < content->huffmanCode[content->pt[i]][0]; j++)
		{
			printf("%d", content->huffmanCode[content->pt[i]][j + 1]);

		}
	}
	printf("\n\n");
	clear(content, top);
	printf("Thank u for using! -- Danis Jiang\n");
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
	char *s = malloc(flen + 1);
	if (!s)
	{
		fclose(fp);
		exit(0);
	}
	fread(s, sizeof(char), flen / sizeof(char), fp);
	s[flen / sizeof(char)] = '\x00';
	Contents* content = (Contents*)malloc(sizeof(Contents));
	content->size = flen / sizeof(char);
	content->pt = s;
	return content;
}

/*****************************************************************
*Function:clear
*Description:清空所有指针
*Calls:free, printf
*Called By:encode
*Input:Contents*, PNode
*Output:clear
*Return:void
*Others:None
*****************************************************************/
void clear(Contents* content, PNode top)
{
	printf("[*]Start to clear memory...\n");
	printf("[*]Clear content->pt\n");
	free(content->pt);
	printf("[*]Clear content->huffmancode\n");
	for (int i = 0; i < 128; i++)
	{
		if (content->frequency[i])
		{
			free(content->huffmanCode[i]);
		}
	}
	free(content->huffmanCode);
	printf("[*]Clear content->frequency\n");
	free(content->frequency);
	printf("[*]Clear content->content\n\n");
	free(content);
}