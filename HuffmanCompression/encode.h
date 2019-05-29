#pragma once
typedef struct Contents
{
	int size;
	char* pt;
	int* frequency;
}Contents;

void encode(char *argv[]);

int* frequency(Contents* content);

Contents* readFile(FILE *fp);