#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int *arr ,int left, int right)
{
	int start=left, end= right, pivot=arr[left];
	while(start<=end)
	{
		while(pivot>=arr[start])
		{
			start++;
		}
		while(pivot<arr[end])
		{
			end--;
		}
		if(start<end)
		{
			swap(arr+start, arr+end);
		}
	}
	swap(arr+left, arr+end);
	return end;
}

void quickSort(int *arr, int left, int right)
{
	if (left<right)
	{
		int loc=partition(arr, left, right);
		quickSort(arr, left, loc-1);
		quickSort(arr, loc+1, right);
	}
}

int main()
{
	int *arr, i , n;
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for (i=0; i<n; i++)
	{
		arr[i]=rand()%n;
	}
	for (i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	clock_t start=clock();
	quickSort(arr,0,n-1);
	clock_t end=clock();
	double cpu_time=((double)(end-start)/CLOCKS_PER_SEC);
	for (i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nCPU TIME %lf",cpu_time);
	return 0;
}
