#include<stdio.h>
#include"encode.h"

void encode(char *argv[])
{
	FILE* inputFp = open(argv[2]);
	char s[1000];
	fscanf_s(inputFp,"%s",s);
	printf("%s",s);
	//int *freq = frequency();
	
	printf("This is encode func\n");
}

int* frequency(char* c)
{
	
}