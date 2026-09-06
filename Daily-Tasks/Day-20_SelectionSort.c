/*
============================================================
Day 20 — Selection Sort
============================================================

PROBLEM NAME:
Selection Sort — Find Minimum and Place It

------------------------------------------------------------
GOAL:
Write a C program that sorts an array using selection sort.

------------------------------------------------------------
REQUIREMENTS:

1. Ask the user for the size of the array (n)
2. Ask the user to enter n elements
3. Implement selection sort:
   - Find the minimum element in unsorted portion
   - Swap it with the first unsorted element
   - Move the boundary between sorted and unsorted
4. Print the array after each pass
5. Print the final sorted array
6. Count and display total swaps

------------------------------------------------------------
RULES:

- Use a function: void selectionSort(int arr[], int n)
- Find minimum in unsorted portion and swap
- Do NOT use bubble sort
- Do NOT use any built-in sort functions

------------------------------------------------------------
CONSTRAINTS:

- Maximum array size: 100
- Elements can be any integer
- Selection sort always does n-1 passes

------------------------------------------------------------
EXAMPLE RUN:

Enter array size: 5
Enter 5 elements: 29 10 14 37 13

Pass 1: 10 29 14 37 13
Pass 2: 10 13 14 37 29
Pass 3: 10 13 14 37 29
Pass 4: 10 13 14 29 37

Sorted array: 10 13 14 29 37
Total swaps: 3

------------------------------------------------------------
CONCEPTS PRACTICED:

- Selection Sort algorithm
- Finding minimum in subarray
- Swapping elements
- Nested loops
- Comparison with Bubble Sort

------------------------------------------------------------
DIFFICULTY: 4/10

------------------------------------------------------------
OPTIONAL HINT:

Selection sort works by finding the minimum element from 
the unsorted part and putting it at the beginning. Think 
about how to track where the unsorted part starts.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-20_SelectionSort.c

COMMIT MESSAGE:
"Add selection sort program"

============================================================
*/

#include <stdio.h>
int swap = 0;
// Write your selectionSort function here
void selectionSort(int arr[], int n) 
{
    int i,j,temp,min;
    for( i=0; i<n-1; i++)
    {
        min = i;
        for( j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min])
                min = j;
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            swap++;
        }
        printf("\nPass %d: ",i+1);
        for(int m=0;m<n;m++)
            printf("%d ",arr[m]);
    }
}

void main() {
    // Write your code here
    // 1. Declare variables
    int arr[100],i,n;

    // 2. Ask for array size
    printf("Enter array size: ");
    scanf("%d",&n);

    // 3. Ask for array elements
    printf("Enter %d elements: ",n);
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);
    
    // 4. Call selectionSort function
    selectionSort(arr,n);

    // 5. Print sorted array
    printf("\n\nSorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    // 6. Print total swaps
    printf("\nTotal swap: %d",swap);

}