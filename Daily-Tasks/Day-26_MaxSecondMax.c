/*
============================================================
Day 26
============================================================

PROBLEM NAME:
Max and Second Max

------------------------------------------------------------
Statement: You are given an array of n integers. Print the
largest value and the SECOND LARGEST DISTINCT value (the
largest value that is strictly smaller than the maximum).
It is guaranteed that the array contains at least two
distinct values.
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each test case consists of two lines:
- the first line contains an integer n (2 <= n <= 1000);
- the second line contains n integers a_1, a_2, ..., a_n
  (1 <= a_i <= 1000).
It is guaranteed that every array has at least two distinct
values.

OUTPUT:
For each test case print two integers: the maximum and the
second maximum distinct value.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 2 <= n <= 1000
- 1 <= a_i <= 1000
- At least two distinct values in every array

------------------------------------------------------------
SAMPLE INPUT:
3
5
3 7 7 1 4
2
9 2
6
5 5 5 2 2 8

SAMPLE OUTPUT:
7 4
9 2
8 5

------------------------------------------------------------
Note: Test 1: maximum is 7; the largest value strictly
smaller than 7 is 4. Test 2: two distinct values, 9 and 2.
Test 3: maximum is 8; the largest value strictly smaller
than 8 is 5 (the 5s appear three times but count once).

------------------------------------------------------------
CONCEPTS PRACTICED:
- Tracking two values in one pass
- Handling duplicates carefully
- Strict vs non-strict comparisons

------------------------------------------------------------
DIFFICULTY: 2/10  (~ Codeforces 800)

------------------------------------------------------------
OPTIONAL HINT:
Keep two variables, best and second. For each x: if x > best,
the old best becomes second and x becomes best; otherwise if
x is bigger than second but strictly smaller than best, update
second. Think about what happens when x equals best.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-26_MaxSecondMax.c

COMMIT MESSAGE:
"Add Day 26 - Max and Second Max"

============================================================
*/

#include <stdio.h>
#include <limits.h>

int main() 
{    
    int t;
    if (scanf("%d", &t) != 1) return 0;    // Used for preventing 'GARBAGE VALUES' 
    while(t>0)
    {
        int i,n,a[10];
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        
        int first_max = INT_MIN;
        int sec_max = INT_MIN;
        
        for(i = 0; i < n; i++) 
        {
            if(a[i] > first_max) 
            {
                sec_max = first_max;
                first_max = a[i];
            } 
            else if(a[i] > sec_max && a[i] < first_max) 
                sec_max = a[i];
        }
        printf("%d %d\n\n",first_max,sec_max);
        t--;
    }
    return 0;
}