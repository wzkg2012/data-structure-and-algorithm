//插入排序
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
