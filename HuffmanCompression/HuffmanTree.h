#pragma once
#include "GLOBAL.h"
#include "FrequencyAnalysis.h"
#include <malloc.h>

PNode createHuffmanTree(PNode * a);

void InorderTraversal(PNode top);

void PreorderTraversal(PNode top);

void PostorderTraversal(PNode top);

void printHuffmanTree(PNode top);

void createHuffmanCoding(PNode top, Contents* content ,int* code , int n);