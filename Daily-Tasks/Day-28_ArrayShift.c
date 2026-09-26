/*
============================================================
Day 28
============================================================

PROBLEM NAME:
Array Shift

------------------------------------------------------------
Statement: You are given an array of n integers. Shift every
element one position to the RIGHT: each element moves to the
next index, and the last element wraps around to become the
first. Print the resulting array.
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each test case consists of two lines:
- the first line contains an integer n (1 <= n <= 1000);
- the second line contains n integers a_1, a_2, ..., a_n
  (1 <= a_i <= 1000).

OUTPUT:
For each test case print the shifted array on one line, with
the numbers separated by single spaces.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= n <= 1000
- 1 <= a_i <= 1000

------------------------------------------------------------
SAMPLE INPUT:
3
4
1 2 3 4
1
7
5
9 8 7 6 5

SAMPLE OUTPUT:
4 1 2 3
7
5 9 8 7 6

------------------------------------------------------------
Note: Test 1: the last element 4 wraps to the front, the rest
move right. Test 2: a single element stays where it is.
Test 3: 5 wraps to the front.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Array index arithmetic with wrap-around
- The % operator for circular indexing
- Printing arrays with controlled spacing

------------------------------------------------------------
DIFFICULTY: 2/10  (~ Codeforces 700)

------------------------------------------------------------
OPTIONAL HINT:
The new array satisfies: result[0] = a[n-1] and
result[i] = a[i-1] for i >= 1. You can also print
a[(i - 1 + n) % n] for every i. Careful: print spaces BETWEEN
numbers, not after the last one.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-28_ArrayShift.c

COMMIT MESSAGE:
"Add Day 28 - Array Shift"

============================================================
*/

#include <stdio.h>

int main() 
{
    int t;
    if (scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        int i,n,ar[1000];
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        
        int temp = ar[n-1];
        for(i=n-1; i>0; i--)
            ar[i]=ar[i-1];
        ar[0]=temp;
        
        for(i = 0; i < n; i++) 
        {
            if(i) printf(" ");
            printf("%d", ar[i]);
        }
        printf("\n");   
    }
}