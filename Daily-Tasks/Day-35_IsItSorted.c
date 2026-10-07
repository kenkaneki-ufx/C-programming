/*
============================================================
Day 35
============================================================

PROBLEM NAME:
Is It Sorted?

------------------------------------------------------------
Statement: You are given an array of n integers. Print "YES"
if the array is sorted in NON-DECREASING order (each element
is >= the previous one), otherwise print "NO".
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each test case consists of two lines:
- the first line contains an integer n (1 <= n <= 1000);
- the second line contains n integers a_1, a_2, ..., a_n
  (1 <= a_i <= 1000).

OUTPUT:
For each test case print "YES" or "NO".

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= n <= 1000
- 1 <= a_i <= 1000

------------------------------------------------------------
SAMPLE INPUT:
3
4
1 2 2 3
5
5 4 3 2 1
3
1 3 2

SAMPLE OUTPUT:
YES
NO
NO

------------------------------------------------------------
Note: Test 1 is non-decreasing (equal neighbors 2 2 are
allowed). Test 2 is decreasing. Test 3 breaks the order at
the 3 -> 2 step.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Comparing neighbours (a[i-1] vs a[i])
- A boolean flag pattern
- Edge case: equal elements are still "sorted"

------------------------------------------------------------
DIFFICULTY: 2/10  (~ Codeforces 700)

------------------------------------------------------------
OPTIONAL HINT:
Remember the previous element while reading. The moment the
current element is SMALLER than the previous one, the answer
is NO — but keep reading the rest of the numbers so the
input stays aligned.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-35_IsItSorted.c

COMMIT MESSAGE:
"Add Day 35 - Is It Sorted"

============================================================
*/

#include <stdio.h>

int main() 
{
    int t;
    if(scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        int i,n,ar[100],sorted=1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=1;i<n;i++)
        {
            if(ar[i-1]>ar[i])
                sorted=0;
        }
        if(sorted) printf("YES\n");
        else printf("NO\n");
        t--;
    }
    return 0;
}
