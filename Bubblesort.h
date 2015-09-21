
//冒泡排序
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
