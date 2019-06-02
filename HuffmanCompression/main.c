#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
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
	if (argc != 3)
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
	printf("\n");
	printf("  _____              _            _ _                   "); printf("\n");
	printf(" |  __ \\            (_)          | (_)                  "); printf("\n");
	printf(" | |  | | __ _ _ __  _ ___       | |_  __ _ _ __   __ _ "); printf("\n");
	printf(" | |  | |/ _` | '_ \\| / __|  _   | | |/ _` | '_ \\ / _` |"); printf("\n");
	printf(" | |__| | (_| | | | | \\__ \\ | |__| | | (_| | | | | (_| |"); printf("\n");
	printf(" |_____/ \\__,_|_| |_|_|___/  \\____/|_|\\__,_|_| |_|\\__, |"); printf("\n");
	printf("                                                   __/ |"); printf("\n");
	printf("                                                  |___/ "); printf("\n");
	printf("\nHuffmanCompression Beta 1.1\n");
	printf("Author: Danis Jiang\n");
	printf("https://github.com/DanisJiang/HuffmanCompression.git \n\n");
	printf("Usage: .\HuffmanCompression.exe [OPTIONS] [INPUT FILE]\n\n");
	printf("General Options: \n");
	printf("	-e		Encode\n");
	printf("	-d		Decode [TODO]\n\n");
	exit(0);
}