/*
============================================================
Day 21 — Insertion Sort
============================================================

PROBLEM NAME:
Insertion Sort — Insert Each Element in Correct Position

------------------------------------------------------------
GOAL:
Write a C program that sorts an array using insertion sort.

------------------------------------------------------------
REQUIREMENTS:

1. Ask the user for the size of the array (n)
2. Ask the user to enter n elements
3. Implement insertion sort:
   - Start from second element (index 1)
   - Compare with elements before it
   - Shift larger elements to the right
   - Insert the element in correct position
4. Print the array after each insertion
5. Print the final sorted array

------------------------------------------------------------
RULES:

- Use a function: void insertionSort(int arr[], int n)
- Shift elements to make space for insertion
- Do NOT use bubble sort or selection sort
- Do NOT use any built-in sort functions

------------------------------------------------------------
CONSTRAINTS:

- Maximum array size: 100
- Elements can be any integer
- Insertion sort is efficient for small or nearly sorted arrays

------------------------------------------------------------
EXAMPLE RUN:

Enter array size: 6
Enter 6 elements: 12 11 13 5 6 7

Inserting 11: 11 12 13 5 6 7
Inserting 13: 11 12 13 5 6 7
Inserting 5: 5 11 12 13 6 7
Inserting 6: 5 6 11 12 13 7
Inserting 7: 5 6 7 11 12 13

Sorted array: 5 6 7 11 12 13

------------------------------------------------------------
CONCEPTS PRACTICED:

- Insertion Sort algorithm
- Shifting elements
- Comparing and inserting
- Partial sorting concept
- Efficiency for nearly sorted data

------------------------------------------------------------
DIFFICULTY: 4/10

------------------------------------------------------------
OPTIONAL HINT:

Think of how you sort playing cards in your hand. You pick 
one card and insert it into its correct position among the 
already sorted cards.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-21_InsertionSort.c

COMMIT MESSAGE:
"Add insertion sort program"

============================================================
*/

#include <stdio.h>

// Write your insertionSort function here
void insertionSort(int arr[], int n) 
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp = arr[i];
        j=i-1;
        while(j>=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        printf("\nInserting %d: ",temp);
        for(int m=0;m<n;m++)
            printf("%d ",arr[m]);

    }
}

void main() {
    // Write your code here
    int arr[100],i,n;
    
    printf("Enter array size: ");
    scanf("%d",&n);

    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    insertionSort(arr,n);
    printf("\n\nSorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
