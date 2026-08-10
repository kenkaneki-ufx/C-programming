#include<stdio.h>
void main()
{
    int ar1[10],ar2[10],ar3[20],n1,n2,i;
    
    printf("Enter size of first Array: ");
    scanf("%d",&n1);
    printf("Enter elements: ");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&ar1[i]);
        ar3[i]=ar1[i];
    }

    printf("Enter size of second Array: ");
    scanf("%d",&n2);
    printf("Enter elements: ");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&ar2[i]);
        ar3[n1+i]=ar2[i];
    }

    printf("The Merged Array is: ");
    for(i=0;i<n1+n2;i++)
        printf("%d ",ar3[i]);
}