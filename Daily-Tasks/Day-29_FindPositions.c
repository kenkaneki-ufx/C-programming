/*
============================================================
Day 29
============================================================

PROBLEM NAME:
Find Positions

------------------------------------------------------------
Statement: You are given an array of n integers and a target
value x. Print the FIRST and the LAST 1-based positions where
x appears in the array. If x does not appear at all, print
"-1 -1".
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each test case consists of three lines:
- the first line contains two integers n and x
  (1 <= n <= 1000, 1 <= x <= 1000);
- the second line contains n integers a_1, a_2, ..., a_n
  (1 <= a_i <= 1000).

OUTPUT:
For each test case print two integers: the first and last
position of x (1-based), or "-1 -1" if x is not present.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= n <= 1000
- 1 <= x, a_i <= 1000

------------------------------------------------------------
SAMPLE INPUT:
3
6 4
1 4 2 4 4 9
5 7
1 2 3 4 5
3 8
8 8 8

SAMPLE OUTPUT:
2 5
-1 -1
1 3

------------------------------------------------------------
Note: Test 1: 4 appears at positions 2, 4 and 5, so the first
is 2 and the last is 5. Test 2: 7 never appears. Test 3: 8
appears at positions 1 through 3.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Linear search with position tracking
- 1-based vs 0-based indexing
- The "not found" sentinel case

------------------------------------------------------------
DIFFICULTY: 3/10  (~ Codeforces 800)

------------------------------------------------------------
OPTIONAL HINT:
Keep two variables, first and last, both starting at -1.
While reading the array, whenever a[i] == x: if first is
still -1 set first to the current position, and always set
last to the current position. Remember to print positions
starting from 1.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-29_FindPositions.c

COMMIT MESSAGE:
"Add Day 29 - Find Positions"

============================================================
*/

#include <stdio.h>

// Write your solution here

int main() 
{
    int t;
    if(scanf("%d",&t) != 1) return 0;
    while (t>0)
    {
        int n,i,x,pos=-1,ar[1005];
        scanf("%d %d",&n,&x);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<n;i++)
        {
            if(ar[i]==x)
            {
                pos = i+1;
                break;
            }
        }
        if(pos==-1)
            printf("%d %d\n\n",pos,pos);
        else
            printf("%d %d\n\n",pos,n-i);
        t--;
    }
}
