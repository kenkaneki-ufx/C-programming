/*
============================================================
Day 18 — Binary Search
============================================================

PROBLEM NAME:
Binary Search — Faster Searching in Sorted Arrays

------------------------------------------------------------
GOAL:
Write a C program that searches for a number in a SORTED array 
using binary search, which is much faster than linear search.

------------------------------------------------------------
REQUIREMENTS:

1. Ask the user for the size of the array (n)
2. Ask the user to enter n elements (MUST BE SORTED in ascending order)
3. Ask the user for the number to search
4. Implement binary search algorithm:
   - Start with low = 0, high = n-1
   - Find mid = (low + high) / 2
   - If arr[mid] == key: found!
   - If arr[mid] < key: search right half (low = mid + 1)
   - If arr[mid] > key: search left half (high = mid - 1)
   - Repeat until found or low > high
5. Print the result (found at index or not found)
6. Use a function for the search logic

------------------------------------------------------------
RULES:

- Use a function: int binarySearch(int arr[], int n, int key)
- The array MUST be sorted before searching
- Do NOT use linear search
- Use only arrays, loops, and functions
- Think about why binary search is faster

------------------------------------------------------------
CONSTRAINTS:

- Maximum array size: 100
- Array must be sorted in ascending order
- Elements can be any integer
- Do not use recursion (iterative version only)

------------------------------------------------------------
EXAMPLE RUN:

Enter array size: 7
Enter 7 elements (sorted): 3 7 12 18 25 31 42
Enter element to search: 25

Found at index 4
Found at position 5

Number of comparisons: 2

------------------------------------------------------------
EXAMPLE RUN 2:

Enter array size: 5
Enter 5 elements (sorted): 10 20 30 40 50
Enter element to search: 35

Element not found in the array

Number of comparisons: 2

------------------------------------------------------------
CONCEPTS PRACTICED:

- Binary Search algorithm
- Sorted array requirement
- Mid calculation
- Search space reduction
- Comparison counting
- Time complexity concept (O(log n) vs O(n))

------------------------------------------------------------
DIFFICULTY: 4/10

------------------------------------------------------------
OPTIONAL HINT:

Binary search works by repeatedly dividing the search space 
in half. Think about what happens when the middle element 
is larger or smaller than what you're looking for.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-18_BinarySearch.c

COMMIT MESSAGE:
"Add binary search program"

============================================================
*/

#include <stdio.h>

// Write your binarySearch function here
int binarySearch(int arr[], int n, int key) 
{
    int low=0, high=n-1, mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if (arr[mid]==key)
            return mid;
        else if (arr[mid]<key)
            low = mid+1;
        else   
            high = mid-1;
    }
    if (low>high)
        return -1;
}

void main() {
    // Write your code here
    // 1. Declare variables
    int arr[100],i,n,key;

    // 2. Ask for array size
    printf("\nEnter array size: ");
    scanf("%d",&n);

    // 3. Ask for sorted array elements
    printf("Enter %d elements (sorted): ",n);
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);

    // 4. Ask for element to search
    printf("Enter element to search: ");
    scanf("%d",&key);

    // 5. Call binarySearch function
    int index = binarySearch(arr,n,key);

    // 6. Print result
    if (index == -1)
        printf("\nElement not found in the array");
    else
        printf("\nFound at index %d\nFound at position %d",index,index+1);
}
