//堆排序
#include "head.h"
void maxHeap(int A[],int index,int len)
{
	int left = 2*index+1;
	int right = 2*index+2;
	int lrg= index;
	if(left<len&&A[left]>A[lrg])
		lrg = left;
	if(right<len&&A[right]>A[lrg])
		lrg = right;
	if(lrg!=index)
	{
		swap(A[lrg],A[index]);
		maxHeap(A,lrg,len/2);
	}
	

}

void heapSort(int A[],int len)
{
	//int len = sizeof(A)/sizeof(int);     
	for(int i=len/2-1;i>=0;i--)
		maxHeap(A,i,len);
	for(int i = len-1;i>0;i--)
	{
		swap(A[i],A[0]);
		maxHeap(A,0,i);
	}
}
