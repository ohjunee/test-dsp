#include "main.h"

typedef struct Node {

	uint8	freq;
	uint8	symbol;

	Node *left, *right;

}Node;

typedef struct Data
{
	FILE* fp_in;
	FILE* fp_out;

	uint8* symbol;
	uint8* input_sequence;
	uint8* freq;

	uint8	n_symbol;
	uint8	output;
	uint8	bitCnt;

}Data;

void free_Tree(Node* node);
bool isEndNode(Node* node);

void QuickSort	(Node** nodeArr, int left, int right);
void swap		(Node **left, Node **right);
void initialize	(Data* data, Node** tail, int n_symbol);

Node*	create_HuffmanTree(Node** nodeArr, uint8* n_symbol);
Node**	createNextFloor(Node* newNode, Node** nodeArr, uint8 arrLen);

void Tree_traversal(Node* node, Data* data, uint8 symbol, int codeword[], int index);

void Extract_symbol	(Data* data, uint8 code_symbol, uint8* index);

void write_AbsValue(Data* data, int codeword[], int index);

void Huffman_Coding(Data* data, uint8 n_symbol, uint8 p_size);

void checkFile		(Data* data, bool Bool);
void Read_Sign		(Data* data, int* predErr_blk, uint8 p_size);
void decoding		(Node* node, Data* data, uint8 p_size);

void memory_alloc1D(Data* data);
void memory_free1D(Data* data);