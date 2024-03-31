#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
    if(a<b)
    return b;
    else if (a>b)
    return a;
}
int min(int a,int b){
    if(a<b)
    return a;
    else if (a>b)
    return b;
}
int Maximum(int * arr,int s, int e)
{
    if(e-s <=1){
        return(max(arr[s],arr[e]));
    }
    else{
        int max1=Maximum(arr, s,(s+e)/2);
        int max2=Maximum(arr, (s+e)/2 + 1,e);
        return (max(max1,max2));
    }
}
int Minimum(int * arr,int s,int e)
{
    if(e-s <= 1){
        return(min(arr[s],arr[e]));
    }
    else{
        int min1=Minimum(arr, s , (s+e)/2 );
        int min2=Minimum(arr, (s+e)/2 +1 , e);
        return (min(min1,min2));
    }
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
    printf("The Maximum element present in the Array is %d \n",Maximum(arr,0,n-1));
    printf("The Minimum element present in the Array is %d \n",Minimum(arr,0,n-1));
}