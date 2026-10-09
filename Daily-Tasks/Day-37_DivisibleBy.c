/*
============================================================
Day 37
============================================================

PROBLEM NAME:
Divisible By

------------------------------------------------------------
Statement: You are given an array of n integers and a number
k. Count how many elements of the array are divisible by k.
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each test case consists of two lines:
- the first line contains two integers n and k
  (1 <= n <= 1000, 1 <= k <= 1000);
- the second line contains n integers a_1, a_2, ..., a_n
  (1 <= a_i <= 1000).

OUTPUT:
For each test case print one integer: the count of elements
divisible by k.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= n <= 1000
- 1 <= k <= 1000
- 1 <= a_i <= 1000

------------------------------------------------------------
SAMPLE INPUT:
3
5 3
3 6 7 9 10
4 5
10 20 30 41
3 7
1 2 3

SAMPLE OUTPUT:
3
3
0

------------------------------------------------------------
Note: Test 1: 3, 6 and 9 are divisible by 3, so the count is
3. Test 2: 10, 20 and 30 are divisible by 5, but 41 is not.
Test 3: none of 1, 2, 3 is divisible by 7.

------------------------------------------------------------
CONCEPTS PRACTICED:
- The % operator in a condition
- Counting with a condition
- Reading two inputs per test case

------------------------------------------------------------
DIFFICULTY: 2/10  (~ Codeforces 700)

------------------------------------------------------------
OPTIONAL HINT:
x is divisible by k exactly when x % k == 0. One loop, one
counter, one comparison.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-37_DivisibleBy.c

COMMIT MESSAGE:
"Add Day 37 - Divisible By"

============================================================
*/

#include <stdio.h>

int main() 
{
    int t;
    if(scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        int n,k,i,ar[100],count=0;
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<n;i++)
        {
            if(ar[i]%k==0)
                count++;
        }
        printf("%d\n",count);
        t--;
    }
}