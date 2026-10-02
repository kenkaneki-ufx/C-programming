/*
============================================================
Day 32
============================================================

PROBLEM NAME:
Sort Swap Count

------------------------------------------------------------
Statement: Sort an array of n integers in ASCENDING order
using bubble sort. Print the sorted array on one line, and
on the next line print how many swaps your bubble sort
performed in total.
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each test case consists of two lines:
- the first line contains an integer n (1 <= n <= 1000);
- the second line contains n integers a_1, a_2, ..., a_n
  (1 <= a_i <= 1000).

OUTPUT:
For each test case print two lines:
- the sorted array, numbers separated by single spaces;
- the total number of swaps performed.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= n <= 1000
- 1 <= a_i <= 1000

------------------------------------------------------------
SAMPLE INPUT:
2
5
5 1 4 2 3
3
1 2 3

SAMPLE OUTPUT:
1 2 3 4 5
6
1 2 3
0

------------------------------------------------------------
Note: For 5 1 4 2 3 the passes are:
5 1 4 2 3 -> 1 5 4 2 3 -> 1 4 5 2 3 -> 1 4 2 5 3 ->
1 4 2 3 5   (4 swaps)
1 4 2 3 5 -> 1 2 4 3 5 -> 1 2 3 4 5   (2 swaps)
Total: 6 swaps. The already-sorted array needs 0 swaps.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Bubble sort implementation from memory
- Counting inside nested loops
- Printing arrays with clean spacing
- (Fun fact: the swap count equals the number of "inversions")

------------------------------------------------------------
DIFFICULTY: 4/10  (~ Codeforces 900)

------------------------------------------------------------
OPTIONAL HINT:
Standard bubble sort: for i from 0 to n-1, for j from 0 to
n-i-1, if a[j] > a[j+1] swap them and increment a counter.
The sorted output must be printed BEFORE the swap count.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-32_SortSwapCount.c

COMMIT MESSAGE:
"Add Day 32 - Sort Swap Count"

============================================================
*/

#include <stdio.h>

int main() {
    int t;
    if(scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        int count=0,temp,i,j,n,arr[100];
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);
        for(i=0; i<n-1; i++)
        {
            for(j=0; j<n-i-1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    count++;
                }
            }
        }
        for(i=0; i<n; i++)
            printf("%d ",arr[i]);
        printf("\n%d\n",count);
        t--;
    }
}
