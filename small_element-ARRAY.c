// WAP to print the position of the smallest number of n numbers using array
#include<stdio.h>
void main()
{
    int arr[10],i,n,pos=0,size,smallest;
    printf("Enter the array size: ");
     scanf("%d",&size);
    printf("Enter the Array:\n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    smallest = arr[pos];
    for(i=1;i<size;i++)
    {
        if(arr[i]<smallest)
        {
            smallest = arr[i];
            pos = i;
        }
    }
    printf("The smallest element %d is at %d position",smallest,pos);
}