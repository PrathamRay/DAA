#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
void mergeArr(int *arr,int p,int q,int r)
{
	int n1,n2;
	n1=q-p+1;
	n2=r-q;
	//int left[n1+2];
	//int right[n2+2];
	int* left=(int*)malloc((n1+2)*sizeof(int));
	int* right=(int*)malloc((n2+2)*sizeof(int));
	for(int i=1;i<=n1;i++)
		left[i]=arr[p+i-1];
	for(int j=1;j<=n2;j++)
		right[j]=arr[q+j];
	
	left[n1+1]=INT_MAX;
	right[n2+1]=INT_MAX;
	
	int i=1,j=1;
	
	for(int k=p;k<=r;k++)
	{
		if(left[i] <= right[j]){
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
	}
	free(left);
	free(right);

}
void mergeSort(int * arr,int s,int e)
{
	if(s>=e)
		return;
	
	int mid=(s+e)/2;
	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);
	mergeArr(arr,s,mid,e);
}

void print(int * arr,int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	clock_t start,end;
	double cpu_time;
	start=clock();
	int n;
	scanf("%d",&n);
	int* arr =(int*)malloc((n+1)*sizeof(int));
	for(int i=1;i<=n;i++)
	{
		arr[i]=rand()%100;
	}
	print(arr,n);
	int s=1,e=n;

	mergeSort(arr,s,e);
	end=clock();
	cpu_time=((double)(end-start))/CLOCKS_PER_SEC;
	print(arr,n);
	printf("Time taken by CPU to execute the code%lf",cpu_time);
	
	free(arr);
}
