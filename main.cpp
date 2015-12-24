//main.cpp
#include "headers.h"
void test();
void testa();
void testb();
int main()
{
	//初始化随机数发生器
	srand((unsigned)time(NULL));
	//srand(123);

	testa();
	testb();
	
	//randRangeSetTest(5);
	//randRangeTest(10, 101, 200);
	//randDblTest(5);
	//randTest(5);
	//test();
	printf("按任意键继续");
	getchar();
	return 0;
}

void testb()
{
	//testRNADP(50);
	testRNADPEx6_7();
	//testKnapsackDP(8);
	//testKnapsackDPEx6_6();
	//testLCSSDP(4, 8, 12);
	//testLCSSDPEx6_5();
	//testTSPDP(8);
	//testTSPDPEx6_1();
	//testClsSubSetNode(4);
	//testBitCounter(128);
	//testPowerOfTwo(20);
}
void testa()
{
	//HuffmanTest(10);
	//HuffmanTestEx5_6();
	//PrimTest(8);
	//PrimEx5_4Test();
	//KruskalTest(8);
	//KruskalEx5_4Test();
	//heapTTest(10);
	//DijkstraTest(9);
	//DijkstraEx5_3Test();
	//traverseDFSTest(8);
	//testAdjList(5);
	//knapsackGreedyTest(5);
	//TSPGreedyTest(5);
	//TSPGreedyEx5_2();
	//TSPGreedyTest(5);
	//quickSortTest(10);
	//pivotDivisionTest(10);
	//mergeSortRTest(10);
	//maxMinTest(10);
	//insertionSortRTest(10);
	//factorialTest(8);
	//heapSortTest(10);
	//mergeSortTest(10);
	//HanoiTest(4);
	//bubbleSortATest(15);
	//binarySearchTest(10);
	//linearSearchTest(10);
	//insertionSortTest(10);
	//reapTest(7);
	//mergeTest(4,6);
	//knockoutTest(5, true);
	//powerTest(2,8);
	//polynomialTest(4);
	//TSPExhaustionTestEx5_2(true);
	//TSPExhaustionTest(5, true);
	//permuteTest(8);
	//chickenSolutionTest(1000);
	//chickenSolutionATest(1000);
	//random9Test(10, 0, 5);
	//euclidGCDTest(5);
	//euclidGCDTest(72, 96, true);
	//bubbleSortTest(10);
}
void test()
{
	//int i=3,j=4;
	//printf("%d %d\n", i, j);
	//swap(&i, &j);
	//printf("%d %d\n", i, j);
}