//Sort the array ascending and descending in order
#include<stdio.h>
void main()
{
    int arr[10],i,j,size,small,temp;
    printf("Enter the array size: ");
     scanf("%d",&size);
    printf("Enter the Array: ");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    for(i = 0; i < size - 1; i++)
    {
        small = i;

        for(j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[small])
                small = j;
        }

        temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
    printf("The sorted Array in ascending: ");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
}
