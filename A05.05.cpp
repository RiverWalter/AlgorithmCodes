//Algorithm 5.5 (P163-4)(A05.05.cpp)
//哈夫曼(Huffman)最优二叉树算法
#include "headers.h"
class ClsNode {
public:
	int index;
	int p;
	int bit;
	int parent;
	int lchild;
	int rchild;
	ClsNode(){};
	void set(int aindex, int ap, int abit, 
		int aparent, int alchild, int archild) {
			index = aindex; 
			p = ap;
			bit = abit;
			parent = aparent;
			lchild = alchild;
			rchild = archild;
	}
	bool operator < (ClsNode &right)
	{
		return p < right.p;
	}
	bool operator > (ClsNode &right)
	{
		return p > right.p;
	}
	ClsNode operator = (ClsNode &right)
	{
		this->set(right.index, right.p, right.bit,
			right.parent, right.lchild, right.rchild);
		return *this;
	}
};
//返回最优二叉树, 调用者负责释放
ClsNode *Huffman(int *p, int n, int &root)
{
	ClsNode *T = new ClsNode[2*n];
	ClsNode *H = new ClsNode[n];
	for (int i=0; i<n; i++) {
		H[i].set(i, p[i], -1, -1, -1, -1);
		T[i].set(i, p[i], -1, -1, -1, -1);
	}
	int m = n; //m:堆中的结点数
	ClsNode x, y, u;
	makeHeapMinT(H, m);
	root = n-1;
	for (int i=0; i<n-1; i++) {
		x = deleteTopMinT(H, m);
		y = deleteTopMinT(H, m);
		u.set(++root, x.p+y.p, -1, -1, x.index, y.index);
		insertMinT(H, m, u);
		T[root] = u;
		T[x.index].bit = 0;
		T[y.index].bit = 1;
		T[x.index].parent = T[y.index].parent = n+i;
	}
	delete H;
	return T;
}
void printHuffmanCoding(ClsNode *T, int root, char *bits, int &level)
{
	if (level)
		bits[level-1] = T[root].bit+48;
	if (T[root].lchild == -1) {
		printf("%c(%d):%s\n", T[root].index+65,
			T[root].p, bits);
	} else {
		level++;
		printHuffmanCoding(T, T[root].lchild, bits, level);
		level++;
		printHuffmanCoding(T, T[root].rchild, bits, level);
	}
	bits[--level] = 0;
}
void printHuffmanTree(ClsNode *T, int root, int &level)
{
	printf("%2d: %3d   %-3d %4d   %4d\n",
		root, level, T[root].p, T[root].lchild, T[root].rchild);
	if (T[root].lchild != -1) {
		level++;
		printHuffmanTree(T, T[root].lchild, level);
		level++;
		printHuffmanTree(T, T[root].rchild, level);
	}
	--level;
}
//p161-162
void HuffmanTestEx5_6()
{
	int p[] = {3, 4, 5, 8, 9, 15, 20, 36};
	int root = -1;
	int n = 8;
	ClsNode *T = Huffman(p, n, root);
	char *bits = new char[2*n];
	for (int i=0; i<2*n; i++)
		bits[i] = 0;
	int level = 0;
	printf("Character frequency:\n");
	for (int i=0; i<n; i++)
		printf("%c:%d ", i+65, p[i]);
	printf("\n");
	printf("Huffman Coding:\n");
	printHuffmanCoding(T, root, bits, level);
	printf("Huffman Tree:\n");
	printf("No: level p   lchild rchild\n");
	level = 0;
	printHuffmanTree(T, root, level);
	delete T, bits;
}
void HuffmanTest(int n)
{
	int *p = new int[n];
	randRangeArr(n, 1, 99, p);
	int root = -1;
	ClsNode *T = Huffman(p, n, root);
	char *bits = new char[2*n];
	for (int i=0; i<2*n; i++)
		bits[i] = 0;
	int level = 0;
	printf("Character frequency:\n");
	for (int i=0; i<n; i++)
		printf("%c:%d ", i+65, p[i]);
	printf("\n");
	printf("Huffman Coding:\n");
	printHuffmanCoding(T, root, bits, level);
	printf("Huffman Tree:\n");
	printf("No: level p   lchild rchild\n");
	level = 0;
	printHuffmanTree(T, root, level);
	delete p, T, bits;
}