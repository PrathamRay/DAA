#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int*,int*);
void swap(int *a, int *b)
{
    int temp=*b;
    *b=*a;
    *a=temp;

}
void selectionSort(int *arr,int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        int minindex=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minindex])
            {
                minindex=j;
            }
        }
        if(minindex!=i)
            swap(&arr[i],&arr[minindex]);
    }
}
void bubbleSort(int *arr,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        int flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
void insertionSort(int *arr,int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        int j=i-1;int temp=arr[i];
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void print(int *arr,int size)
{
    int i;
    printf("\nYour Array is \n");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    clock_t start,end;
	double CPUtime;
	start=clock();

	printf("Enter the size of the array\n");
	int size;
	scanf("%d",&size);
	int * arr;
	int i;
	arr=(int*)malloc(size * sizeof(int));
	// printf("Enter the element of the array\n");
	for(i=0;i<size;i++)
	// scanf("%d",&arr[i]);
	arr[i]=rand()%size;
	print(arr,size);

	bubbleSort(arr,size);
	// selectionSort(arr,size);
	// insertionSort(arr,size);
	printf("After sorting");
	print(arr,size);
	end=clock();
	CPUtime=((double)(end-start))/CLOCKS_PER_SEC;
	printf("CPU time is %lf",CPUtime);
	free(arr);
	return 0;
}
