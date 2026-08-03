#include <stdio.h>

void main() 
{
    int n,choice,num,pos,size=10;
    int arr[20]={23,24,0,0,26,27,28,0};
    printf("The list is: ");
    for(n=0;n<size;n++)
    {
        if(arr[n]!=0)
            printf("%d ",arr[n]);
        else 
            printf("_ ");
    }
    while (1==1)
    {//choices for INSERTING and DELETING elements in the ARRAY-LIST
    printf("\nEnter your choice:\n1.Insertion  2.Deletion\n");
    scanf("%d",&choice);
    insert:
    if (choice==1)
    {
        printf("\nEnter the Number to insert: ");
        scanf("%d",&num);
        if (num==0)
            {//if inserted number is zero it acts like a '_' in the list
                printf("Enter a non-zero number.\n");
                goto insert;
            }
        printf("Enter the index to insert (0-%d): ",size);
        scanf("%d",&pos);
        for(n=size;n>pos;n--)
        {
            if(arr[pos]==0)
            {
                arr[pos]=num;
                size--;
                break;
            }
            arr[n]=arr[n-1];
        }
        arr[pos]=num;
        size++;
    }
    
    else if (choice==2)
    {
        printf("\nEnter the index to delete (0-%d): ",size);
        scanf("%d",&pos);
        for(n=pos;n<size;n++)
            arr[n]=arr[n+1];
        size--;
    }
    else
        printf("Invalid choice\n");
    printf("The List is:\n");
    for(n=0;n<size;n++)
    {
        if(arr[n]!=0)
            printf("%d ",arr[n]);
        else 
            printf("_ ");
    }
    }
}