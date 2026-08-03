//Sort the array ascending and descending in order
#include<stdio.h>
void main()
{
    int arr[10],i,size,small,temp;
    printf("Enter the array size: ");
     scanf("%d",&size);
    printf("Enter the Array: ");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    small = arr[0];
    for(i=1;i<size;i++)
    {
        if(small>arr[i])
        {
            temp = arr[i];
            arr[i] = small;
            small = temp;
        }
    }
    printf("The sorted Array in ascending: ");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
}

// take a two array and merge them in ascending order