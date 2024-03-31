#include<stdio.h>
#include<stdlib.h>
void QuickSort(int* arr,int s,int e)
{
    if(s<e)
    {
        int piv=PivotElement(arr,s,e);
        QuickSort(arr,s,piv-1);
        QuickSort(arr,piv+1,e);
    }
}
int PivotElement(int * arr,int s,int e)
{
    int x=arr[e];
    int i=s-1;
    for(int j=s;j<e;j++)
    {
        if(arr[j] <= x)
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[e];
    arr[e]=temp;
    return i+1;
}
int main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int * arr=(int *)malloc(sizeof(int)*n);
    printf("Enter the elements in the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    QuickSort(arr,0,n-1);
    printf("Sorted Array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}