/*
============================================================
Day 23 — Frequency Count
============================================================

PROBLEM NAME:
Count Frequency of Each Element in Array

------------------------------------------------------------
GOAL:
Write a C program that counts how many times each element 
appears in an array.

------------------------------------------------------------
REQUIREMENTS:

1. Ask the user for the size of the array (n)
2. Ask the user to enter n elements
3. Count frequency of each element
4. Print each element with its frequency
5. Find and print:
   - Most frequent element
   - Least frequent element
   - Elements that appear exactly once

------------------------------------------------------------
RULES:

- Use functions for frequency counting
- Do NOT sort the array
- Handle duplicate counting correctly
- Print results in a clear format

------------------------------------------------------------
CONSTRAINTS:

- Maximum array size: 100
- Elements can be any integer
- Consider: what if multiple elements have same frequency?

------------------------------------------------------------
EXAMPLE RUN:

Enter array size: 10
Enter 10 elements: 1 2 3 2 1 4 1 2 3 1

Frequency Count:
1 -> 4 times
2 -> 3 times
3 -> 2 times
4 -> 1 time

Most frequent: 1 (appears 4 times)
Least frequent: 4 (appears 1 time)
Elements appearing once: 4

------------------------------------------------------------
CONCEPTS PRACTICED:

- Frequency counting
- Array traversal
- Counting with arrays
- Finding extremes (max/min frequency)
- Data analysis basics

------------------------------------------------------------
DIFFICULTY: 5/10

------------------------------------------------------------
OPTIONAL HINT:

You can use a separate array to store frequencies, or 
count occurrences by comparing each element with all others.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-23_FrequencyCount.c

COMMIT MESSAGE:
"Add frequency count program"

============================================================
*/

#include <stdio.h>
void countFrequency(int arr[], int n)
{
    int visited[100] = {0};
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 1)
            continue;
        int count = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;    
                visited[j] = 1;
            }
        }
        printf("%d -> %d times\n", arr[i], count);
    }
}

void main() {
    int arr[100],i,n;

    printf("Enter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countFrequency(arr,n);
}
