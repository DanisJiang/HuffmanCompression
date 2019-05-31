#pragma once
#include "GLOBAL.h"
#include "FrequencyAnalysis.h"
#include <malloc.h>

PNode createHuffmanTree(PNode * a);

void InorderTraversal(PNode top);

void PreorderTraversal(PNode top);

void PostorderTraversal(PNode top);

void printHuffmanTree(PNode top);

int* huffmanCoding(PNode top);