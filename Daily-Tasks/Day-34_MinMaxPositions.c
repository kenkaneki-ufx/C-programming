/*
============================================================
Day 34
============================================================

PROBLEM NAME:
Min and Max Positions

------------------------------------------------------------
Statement: You are given an array of n integers. Print the
1-based position of the SMALLEST element and the 1-based
position of the LARGEST element. If the smallest or largest
value appears several times, use its FIRST occurrence.
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each test case consists of two lines:
- the first line contains an integer n (1 <= n <= 1000);
- the second line contains n integers a_1, a_2, ..., a_n
  (1 <= a_i <= 1000).

OUTPUT:
For each test case print two integers: the position of the
minimum and the position of the maximum, separated by a
space.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= n <= 1000
- 1 <= a_i <= 1000

------------------------------------------------------------
SAMPLE INPUT:
3
5
3 1 4 1 5
1
42
6
7 7 7 2 9 9

SAMPLE OUTPUT:
2 5
1 1
4 5

------------------------------------------------------------
Note: Test 1: the minimum 1 first appears at position 2, the
maximum 5 is at position 5. Test 2: a single element is both
the min and the max. Test 3: the minimum 2 is at position 4,
the maximum 9 first appears at position 5 (not 6).

------------------------------------------------------------
CONCEPTS PRACTICED:
- Finding extremes WITH positions in one pass
- First-occurrence rule (strict vs non-strict comparison)
- 1-based output positions

------------------------------------------------------------
DIFFICULTY: 2/10  (~ Codeforces 700)

------------------------------------------------------------
OPTIONAL HINT:
Track minVal, maxVal, minPos, maxPos while reading. Update a
position only when you find a STRICTLY smaller / STRICTLY
bigger value — that is exactly what keeps the first
occurrence.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-34_MinMaxPositions.c

COMMIT MESSAGE:
"Add Day 34 - Min and Max Positions"

============================================================
*/

#include <stdio.h>

int main() 
{
    int t;
    if(scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        int n,i,arr[100],min=0,max=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        for(i=1;i<n;i++)
        {   
            if(arr[i]<arr[min])
                min = i;
            if(arr[i]>arr[max])
                max = i;
        }
        printf("%d %d\n",min+1,max+1);
        t--;
    }
}
