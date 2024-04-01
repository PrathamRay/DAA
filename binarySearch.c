#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binarySearch(int * arr, int s,int e,int key)
{
	if(s>=e)
		return -1;
	int mid=(s+e)/2;
	if(key == arr[mid])
		return  mid;
	else if(key<arr[mid])
		binarySearch(arr,s,mid,key);
	else if(key>arr[mid])
		binarySearch(arr,mid+1,e,key);	
}
void main()
{
	int n;
	int * arr;
	printf("Enter the size\n");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter the key element to be searched\n");
	int key;
	scanf("%d",&key);
	int index=binarySearch(arr,0,n-1,key);
	if(index == -1)
		printf("Element Not Found\n");
	else
		printf("Element Found at %d\n",index+1);	
}
