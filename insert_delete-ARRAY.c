#include <stdio.h>
void DISPLAY(int *ar,int n)
{
    printf("\nCurrent list:\n[ ");
    for(int i=0;i<n;i++)
    {
        if(ar[i]!=0)
            printf("%d ",ar[i]);
        else 
            printf("_ ");
    }
    printf(" ]\n");
}

int INSERT(int *ar,int n)
{
    int pos,num,i;
    insert: 
    printf("\nEnter the Number to insert: ");
    scanf("%d",&num);
    if (num==0)
    {// if inserted number is zero it acts like a '_' in the list
        printf("Enter a non-zero number.\n");
        goto insert;
    }
    printf("Enter the position to insert (0-%d): ",n-1);
    scanf("%d",&pos);
    if(pos<0||pos>n)
        printf("Invalid position..");
    else
    {
        if(ar[pos]==0)
            ar[pos]=num;
        else
        {   // Insertion logic 
            for(i=n;i>pos;i--)
                ar[i]=ar[i-1];
            n++;
            ar[pos]=num;
        }
    }
    DISPLAY(ar,n);
    return n;
}

int DELETE(int *ar,int n)
{
    int pos,i;
    printf("\nEnter the position to delete (0-%d): ",n-1);
    scanf("%d",&pos);
    if (ar[pos]==0)
        printf("Position is already empty.");
    else
    {
        if (pos<0||pos>=n)
            printf("Invalid position..");
        else
        {   // Deletion logic
            for(i=pos;i<n-1;i++)
                ar[i]=ar[i+1];
            n--;
        }
    }
    DISPLAY(ar,n);
    return n;
}

void main() 
{
    int n,choice,num,pos,size=10;
    int ar[20]={23,24,0,0,26,0,27,28,0,0};
    printf("==================================\n");
    printf("        ARRAY LIST PROGRAM        \n");
    printf("==================================\n");
    DISPLAY(ar,size);
    while (1==1)
    {
        printf("\n1.Insertion");
        printf("\n2.Deletion");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        if (choice==1)        
            size = INSERT(ar,size);
        else if (choice==2)
            size = DELETE(ar,size);
        else if (choice==3)
            DISPLAY(ar,size);
        else if (choice==4)
            break;
        else
            printf("Invalid choice\n");
    }
}