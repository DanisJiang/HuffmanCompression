#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encode.h"
#include "decode.h"

void error();

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

void error()
{

	printf("\nHuffmanCompression Beta 0.0.0\n");
	printf("Author: Danis Jiang\n");
	printf("https://github.com/DanisJiang/HuffmanCompression.git \n\n");
	printf("Usage: .\HuffmanCompression.exe [OPTIONS] [INPUT FILE] [OUTPUT FILE]\n\n");
	printf("General Options: \n");
	printf("	-e		Encode\n");
	printf("	-d		Decode\n\n");
}