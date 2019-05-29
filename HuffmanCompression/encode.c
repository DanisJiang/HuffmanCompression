#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"encode.h"


/*****************************************************************
*Function:encode
*Description:加密模块
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
	for (int i = 0; i < 128; i++)
	{
		if (content->frequency[i])
		{
			printf("\"%c\": %d ", i, content->frequency[i]);
		}
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