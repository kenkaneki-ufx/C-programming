// WAP to print the position of the smallest number of n numbers using array
#include<stdio.h>
void smallest(int *arr,int n)
{
    int i,smallest = arr[0];
    for(i=1;i<n;i++)
    {
        if(smallest > arr[i])
        {
            smallest = arr[i];
            break;
        }
    }
    printf("\nThe smallest element %d is at %d position",smallest,i);
}
void largest(int *arr,int n)
{
    int i,largest = arr[0];
    for(i=0;i<n;i++)
    {
        if (largest < arr[i])
        largest = arr[i];
        break;
    }
    printf("\nThe largest element %d is at %d position",largest,i);
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