#pragma once
#include "GLOBAL.h"
#include "FrequencyAnalysis.h"
#include <malloc.h>

PNode createHuffmanTree(PNode * a);

int* huffmanCoding(PNode top);