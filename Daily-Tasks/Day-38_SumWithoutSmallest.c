/*
============================================================
Day 38
============================================================

PROBLEM NAME:
Sum Without the Smallest

------------------------------------------------------------
Statement: You are given an array of n integers. Print the
sum of ALL elements EXCEPT one occurrence of the smallest
element. Equivalently: compute the total sum, then subtract
the smallest value once.
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each test case consists of two lines:
- the first line contains an integer n (1 <= n <= 1000);
- the second line contains n integers a_1, a_2, ..., a_n
  (1 <= a_i <= 1000).

OUTPUT:
For each test case print one integer: the total sum minus
one occurrence of the smallest element.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= n <= 1000
- 1 <= a_i <= 1000

------------------------------------------------------------
SAMPLE INPUT:
3
4
5 2 8 2
1
10
5
1 1 1 1 1

SAMPLE OUTPUT:
15
0
4

------------------------------------------------------------
Note: Test 1: total 17, smallest 2, so 17 - 2 = 15 (only one
of the two 2s is removed). Test 2: the only element IS the
smallest, so nothing remains: 0. Test 3: total 5, minus one
1 = 4.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Combining a running sum with a running minimum
- Single-pass thinking
- Edge case: n = 1

------------------------------------------------------------
DIFFICULTY: 3/10  (~ Codeforces 800)

------------------------------------------------------------
OPTIONAL HINT:
Track sum and min in the same reading loop. The answer is
simply sum - min. Check your code against the n = 1 case:
it must print 0.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-38_SumWithoutSmallest.c

COMMIT MESSAGE:
"Add Day 38 - Sum Without the Smallest"

============================================================
*/

#include <stdio.h>

int main() 
{
    int t;
    if(scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        int n,ar[100],i,sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        int min = ar[0];
        for(i=0;i<n;i++)
        {
            sum+=ar[i];
            if(ar[i]<min)
                min = ar[i];
        }
        printf("%d\n",sum-min);
        t--;
    }
    return 0;
}
