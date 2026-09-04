/*
============================================================
Day 19 — Bubble Sort
============================================================

PROBLEM NAME:
Bubble Sort — Sort an Array Using Swaps

------------------------------------------------------------
GOAL:
Write a C program that sorts an array in ascending order 
using the bubble sort algorithm.

------------------------------------------------------------
REQUIREMENTS:

1. Ask the user for the size of the array (n)
2. Ask the user to enter n elements
3. Implement bubble sort:
   - Compare adjacent elements
   - Swap if they are in wrong order
   - Repeat for n-1 passes
4. Print the array after each pass (to see the sorting process)
5. Print the final sorted array
6. Count and display the total number of swaps

------------------------------------------------------------
RULES:

- Use a function: void bubbleSort(int arr[], int n)
- Use only arrays and loops (no recursion)
- Do NOT use any built-in sort functions
- Compare adjacent elements and swap them

------------------------------------------------------------
CONSTRAINTS:

- Maximum array size: 100
- Elements can be any integer
- Optimize if possible: if no swaps in a pass, array is sorted

------------------------------------------------------------
EXAMPLE RUN:

Enter array size: 5
Enter 5 elements: 64 34 25 12 22

Pass 1: 34 25 12 22 64
Pass 2: 25 12 22 34 64
Pass 3: 12 22 25 34 64
Pass 4: 12 22 25 34 64

Sorted array: 12 22 25 34 64
Total swaps: 7

------------------------------------------------------------
CONCEPTS PRACTICED:

- Bubble Sort algorithm
- Nested loops
- Swapping two variables
- Pass-by-reference (arrays)
- Counting operations

------------------------------------------------------------
DIFFICULTY: 4/10

------------------------------------------------------------
OPTIONAL HINT:

Think about how many passes you need. In each pass, the 
largest unsorted element "bubbles up" to its correct position.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-19_BubbleSort.c

COMMIT MESSAGE:
"Add bubble sort program"

============================================================
*/

#include <stdio.h>
int swap = 0;
// Write your bubbleSort function here
void bubbleSort(int arr[], int n) 
{    
    int i,j,temp;
    for( i=0; i<n-1; i++)
    {
        int flag=0;
        for( j=0; j<n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap++;
                flag = 1;
            }
        }
        printf("\nPass %d: ",i+1);
        for(int m=0;m<n;m++)
            printf("%d ",arr[m]);
        if(flag==0)
            break;
    }
}

void main() {
    // Write your code here
    // 1. Declare variables
    int arr[100],n,i;

    // 2. Ask for array size
    printf("Enter array size: ");
    scanf("%d",&n);

    // 3. Ask for array elements
    printf("Enter %d elements: ",n);
    for( i=0; i<n; i++)
        scanf("%d",&arr[i]);

    // 4. Call bubbleSort function
    bubbleSort(arr,n);

    // 5. Print sorted array
    printf("\n\nSorted array: ");
    for(i=0; i<n;i++)
        printf("%d ",arr[i]);
    
    // 6. Print total swaps
    printf("\nTotal swap: %d",swap);
    
}
