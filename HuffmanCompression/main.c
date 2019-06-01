#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encode.h"
#include "decode.h"


/*****************************************************************
*Function:main
*Description:主函数
*Calls:encode, decode, error
*Called By:None
*Input:int, int*
*Output:None
*Return:void
*Others:None
*****************************************************************/
int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		error();
		return 0;
	}
	if (!strcmp(argv[1], "-e"))
	{
		encode(argv);
	}
	else if (!strcmp(argv[1], "-d"))
	{
		decode(argv);
	}
	else
	{
		error();
		return 0;
	}
	return 0;
}

/*****************************************************************
*Function:error
*Description:Usage
*Calls:printf
*Called By:main
*Input:void
*Output:info
*Return:void
*Others:None
*****************************************************************/
void error()
{

	printf("\nHuffmanCompression Beta 1.0\n");
	printf("Author: Danis Jiang\n");
	printf("https://github.com/DanisJiang/HuffmanCompression.git \n\n");
	printf("Usage: .\HuffmanCompression.exe [OPTIONS] [INPUT FILE] [OUTPUT FILE]\n\n");
	printf("General Options: \n");
	printf("	-e		Encode\n");
	printf("	-d		Decode\n\n");
}