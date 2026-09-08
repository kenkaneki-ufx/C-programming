/*
============================================================
Day 22 — Array Duplicate Detection
============================================================

PROBLEM NAME:
Find and Remove Duplicates from Array

------------------------------------------------------------
GOAL:
Write a C program that finds duplicate elements in an array 
and creates a new array with only unique elements.

------------------------------------------------------------
REQUIREMENTS:

1. Ask the user for the size of the array (n)
2. Ask the user to enter n elements (may have duplicates)
3. Find all duplicate elements
4. Create a new array with only unique elements
5. Print:
   - Original array
   - List of duplicate elements found
   - Array after removing duplicates
   - Count of unique elements

------------------------------------------------------------
RULES:

- Use functions for:
  - Finding duplicates
  - Removing duplicates
- Do NOT sort the array first
- Preserve original order of first occurrence
- Do NOT use any built-in functions for this

------------------------------------------------------------
CONSTRAINTS:

- Maximum array size: 100
- Elements can be any integer
- Consider: what if there are multiple duplicates of same element?

------------------------------------------------------------
EXAMPLE RUN:

Enter array size: 8
Enter 8 elements: 1 3 5 3 7 1 9 5

Original array: 1 3 5 3 7 1 9 5
Duplicates found: 3, 1, 5
Array after removing duplicates: 1 3 5 7 9
Unique elements count: 5

------------------------------------------------------------
CONCEPTS PRACTICED:

- Array traversal
- Duplicate detection
- Array manipulation
- Nested loops
- Counting occurrences

------------------------------------------------------------
DIFFICULTY: 5/10

------------------------------------------------------------
OPTIONAL HINT:

For each element, check if it has appeared before at any 
earlier index. If not, it's the first occurrence - keep it.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-22_ArrayDuplicate.c

COMMIT MESSAGE:
"Add array duplicate detection program"

============================================================
*/
#include <stdio.h>

void findDuplicates(int arr[], int n)
{
    int i,j,m = 0,dup[100],found[100] = {0};
    printf("\nDuplicates found: ");
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                // Check if we already added this duplicate
                int already = 0;
                for(int k = 0; k < m; k++)
                {
                    if(dup[k] == arr[i])
                    {
                        already = 1;
                        break;
                    }
                }
                
                // If not already added and not marked
                if(!already && !found[i])
                {
                    dup[m] = arr[i];
                    m++;
                    found[i] = 1;
                }
                break;
            }
        }
    }
    
    for(i = 0; i < m; i++)
    {
        printf("%d", dup[i]);
        if(i < m-1)
            printf(", ");
    }
    if(m == 0)
        printf("None");
    printf("\n");
}

int removeDuplicates(int arr[], int n, int result[])
{
    int i, j, k = 0;
    for(i = 0; i < n; i++)
    {
        // Check if arr[i] is already in result
        int isDup = 0;
        for(j = 0; j < k; j++)
        {
            if(arr[i] == result[j])
            {
                isDup = 1;
                break;
            }
        }
        // If not duplicate, add to result
        if(!isDup)
        {
            result[k] = arr[i];
            k++;
        }
    }
    return k;
}

void main()
{
    int arr[100], n, i;
    int unique[100];
    
    printf("Enter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("\nOriginal array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    findDuplicates(arr, n);
    
    int count = removeDuplicates(arr, n, unique);
    
    printf("Array after removing duplicates: ");
    for(i = 0; i < count; i++)
        printf("%d ", unique[i]);
    
    printf("\nUnique elements count: %d\n", count);
}
