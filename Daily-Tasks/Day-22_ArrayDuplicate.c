/*
============================================================
Day 22 - Array Duplicate Detection
============================================================
*/

#include <stdio.h>

void findDuplicates(int arr[], int n)
{
    int i, j, m = 0;
    int dup[100];
    int found[100] = {0};
    
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
    
    // Print duplicates
    for(i = 0; i < m; i++)
    {
        printf("%d", dup[i]);
        if(i < m - 1)
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
    
    // Print original array
    printf("\nOriginal array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    // Find duplicates
    findDuplicates(arr, n);
    
    // Remove duplicates
    int count = removeDuplicates(arr, n, unique);
    
    // Print result
    printf("Array after removing duplicates: ");
    for(i = 0; i < count; i++)
        printf("%d ", unique[i]);
    
    printf("\nUnique elements count: %d\n", count);
}
