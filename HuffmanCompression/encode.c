#include<stdio.h>
#include<string.h>
#include"encode.h"

void encode(char *argv[])
{
	FILE* inputFp;
	errno_t err;
	if (err = fopen_s(&inputFp, argv[2],"r"))
	{
		printf("error: no such file");
		exit(0);
	}
	else
	{
		printf("success to open %s\n\n", argv[2]);
	}
	char s[1000];
	if (!readFile(inputFp, s))
	{
		printf("error: failed to read file");
		exit(0);
	}
	printf("%s",s);
	//int *freq = frequency();
}

int readFile(FILE *fp, char* s)
{
	int i = 0;
	while (fgets(fp, 1000, s+i))
	{
		i += strlen(s);
	}
}

int* frequency(char* c)
{
	
}