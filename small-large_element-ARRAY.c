// WAP to print the position of the smallest number of n numbers using array
#include<stdio.h>
void smallest(int *arr,int n)
{
    int i,pos=0,smallest = arr[pos];
    for (i=1;i<n;i++)
    {
        if(arr[i]<smallest)
        {
            smallest = arr[i];
            pos = i;
        }
    }
    printf("\nThe smallest element %d is at %d position",smallest,pos);
}
void largest(int *arr,int n)
{
    int i,pos=0,largest = arr[pos];
    for(i=0;i<n;i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
            pos = i;
        }
    }
    printf("\nThe largest element %d is at %d position",largest,pos);
}

int main()
{
    int arr[10],size;
    printf("Enter the array size: ");
     scanf("%d",&size);
    printf("Enter the Array: ");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    smallest(arr,size);
    largest(arr,size);    
    return 0;
}