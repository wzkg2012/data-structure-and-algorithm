//#include "head.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;
//#include "head.h"
//#include "swap.h"
void swap(int &a,int &b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void Bubblesort(int A[],int len)
{
  bool flag= false;
  for(int i=len-1;i>=0;i--)
  {
    for(int j=0;j<i;j++)
    {
     if(A[j]>A[i])
    {
      int temp=A[i];
      A[i]=A[j];
      A[j]=temp;
      flag=true;
    }
    }
    if (!flag)
    break;
  }
}

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

void insertionSort(int A[],int left,int right)
{
  int temp;
  int j ;
  for(int i =left+1;i<=right;i++)
  {
    temp = A[i];
    for( j = i;j>left&&A[j-1]>temp;j--)
    {
      A[j] = A[j-1];
    }
      A[j] = temp;                      //这个不放再for循环里面可以减少一些移动
  }
}

void Merge(int A[],int left,int right)
{
 int center= (left+right)/2;
 int Lpos=left;
 int Rpos=center+1;
 int Num = right-left+1;
 int * B = new int [Num];
 int totalPos=0;
 while(Lpos<=center&&Rpos<=right)
 {
  if(A[Lpos]>A[Rpos])
  {
    B[totalPos++]=A[Rpos++];
  }
  else
  {
      B[totalPos++]=A[Lpos++];
  }
}
  while(Lpos<=center)
{
  B[totalPos++]=A[Lpos++];
}
  while(Rpos<=right)
{
  B[totalPos++]=A[Rpos++];
}
  for(int i=0;i<Num;i++)
{
 A[i+left]=B[i];
}
delete B;
}

void Msort(int A[],int left,int right)
{
 int center;
 if(left<right)
 {
  center=(left+right)/2;
  Msort(A,left,center);
    Msort(A,center+1,right);
  Merge(A,left,right);
  
 }
}

#define cutoff 3
int Median(int A [],int left,int right)
{
  //int len = sizeof(A)/sizeof(int);
    //int median;
    int center = (right+left)/2;

  if(A[left]>A[center])
    swap(A[left],A[center]);
  if(A[left]>A[right])
    swap(A[left],A[center]);
  if(A[center]>A[right])
    swap(A[right],A[center]);
  swap(A[center],A[right-1]);                      //经过三数中值分割法后right比枢纽元要大，所以要将枢纽元放在right-1的位置
  return A[right-1];
  
}

void quickSort(int A[],int left,int right)
{
  if(left+cutoff<=right)
  {
    int key = Median(A,left,right);
    int j = right-2;                              //在这个地方犯了一个错误，在数据结构与算法分析上也有说这个错误
    int i = left+1;                               //i从left+ 1开始，是三数中值分割法后，left比枢纽元要小

    while(1)
    {
      while(A[i++]<key){};
      while(A[j--]>key){};
      if(i<j)
        swap(A[--i],A[++j]);                 //这里做了自加和自减操作，是因为这里前面的i++和j--，所以要将索引移回去再交换，虽然是一个细节，但是当时在这里检查了好久才发现这个大虫
      else
        break;
    }
    swap(A[i],A[right-1]);
    quickSort(A,left,i-1);
    quickSort(A,i+1,right);                
  }
  else
    insertionSort(A,left,right); 
}

int main()
{
  int A[100000] = {0};
  clock_t start,finish;
  double totaltime;
  srand((unsigned)time(NULL));
  int index;
  for(int i=0;i<100000;i++)
  {
   A[i]=rand();
  }
  cout<<"please choose number of the sorting way"<<endl;
  cout<<"1.Bubble sorting  "<<endl;
  cout<<"2.Merge sorting"<<endl;
  cout<<"3 Quick sorting"<<endl;
  cout<<"4 Insertion sorting"<<endl;
  cout<<"5 heap sorting"<<endl;


  cin>>index;
  start=clock();
  switch (index)
  {
  case 1:
  Bubblesort(A,sizeof(A)/sizeof(int));break;
  case 2:
  Msort(A,0,sizeof(A)/sizeof(int)-1);break;
  case 3:
  quickSort(A,0,sizeof(A)/sizeof(int)-1);break;
  case 4:
  insertionSort(A,0,sizeof(A)/sizeof(int)-1);break;
  case 5:
  heapSort(A,sizeof(A)/sizeof(int));break;
  default:
  cout<<"please input the right number"<<endl;
  sleep(5);
  return 0;
  }
  finish=clock();
  totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
  cout<<"after sorting"<<endl;
  for(int i=0;i<sizeof(A)/sizeof(int);i++)
	{
		cout<<A[i]<<"  ";
	}  
  cout<<endl;
  cout<<"and time consume is "<<totaltime<<endl;
  
}
