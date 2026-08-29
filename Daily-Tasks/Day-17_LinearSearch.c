/*
============================================================
Day 17 — Linear Search
============================================================
PROBLEM NAME:
Linear Search — Find an Element in an Array
------------------------------------------------------------
GOAL:
Write a C program that searches for a specific number in an 
array and reports whether it was found and at which position.
------------------------------------------------------------
REQUIREMENTS:
1. Ask the user for the size of the array (n)
2. Ask the user to enter n elements
3. Ask the user for the number to search
4. Search the array element by element (from index 0 to n-1)
5. If found:
   - Print "Found at index X"
   - Print "Found at position X" (position = index + 1)
6. If not found:
   - Print "Element not found in the array"
7. Use a function for the search logic
------------------------------------------------------------
RULES:
- Use a function: int linearSearch(int arr[], int n, int key)
- The function should return the INDEX if found, -1 if not found
- Do NOT sort the array
- Do NOT use any built-in search functions
- Use a loop to check each element one by one
------------------------------------------------------------
CONSTRAINTS:
- Maximum array size: 100
- Array elements can be any integer (positive, negative, zero)
- The element to search can appear multiple times (find first occurrence)
- Use only arrays, loops, and functions (no recursion needed yet)
------------------------------------------------------------
EXAMPLE RUN:
Enter array size: 6
Enter 6 elements: 12 45 7 23 89 45
Enter element to search: 23
Found at index 3
Found at position 4
------------------------------------------------------------
EXAMPLE RUN 2:
Enter array size: 5
Enter 5 elements: 10 20 30 40 50
Enter element to search: 35
Element not found in the array
------------------------------------------------------------
CONCEPTS PRACTICED:
- Arrays
- Functions
- Linear Search algorithm
- Loop with early exit (break)
- Return values from functions
- Index vs Position
------------------------------------------------------------
DIFFICULTY: 3/10
------------------------------------------------------------
OPTIONAL HINT:
Think about what happens when you find the element. Do you 
need to continue searching? What should the function return?
------------------------------------------------------------
FILENAME SUGGESTION:
Day-17_LinearSearch.c
COMMIT MESSAGE:
"Add linear search program"
============================================================
*/
#include <stdio.h>
// Write your linearSearch function here
int linearSearch(int arr[], int n, int key) {
   for(int i=0; i<n; i++)
   {
      if(arr[i]==key)
         return i;
   }   
   return -1;
}
void main() 
{
   int arr[20],n,key,i;
   printf("\nEnter array size: ");
   scanf("%d",&n);
   printf("Enter %d elements: ",n);
   for(i = 0; i < n; i++)
      scanf("%d",&arr[i]);
   
   printf("Enter element to search: ");
   scanf("%d",&key);
   int index = linearSearch(arr,n,key);
   
   if(index == -1)
      printf("Element not found in the array\n");
   else
      printf("Found at position %d\n",index+1);
}
