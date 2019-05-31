﻿#pragma once
typedef struct Contents
{
	int size;
	char* pt;
	int* frequency;
}Contents;

typedef struct HuffmanTreeNode
{
	int weight;
	int value;
	struct HuffmanTreeNode* LChild;
	struct HuffmanTreeNode* RChild;
}Node,*PNode;