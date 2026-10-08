/*
============================================================
Day 36
============================================================

PROBLEM NAME:
Count Distinct

------------------------------------------------------------
Statement: You are given n integers, each between 1 and 100.
Count how many DIFFERENT values appear in the array.
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each test case consists of two lines:
- the first line contains an integer n (1 <= n <= 1000);
- the second line contains n integers a_1, a_2, ..., a_n
  (1 <= a_i <= 100).

OUTPUT:
For each test case print one integer: the number of distinct
values.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= n <= 1000
- 1 <= a_i <= 100

------------------------------------------------------------
SAMPLE INPUT:
3
6
1 2 2 3 3 3
1
9
8
5 5 5 5 5 5 5 5

SAMPLE OUTPUT:
3
1
1

------------------------------------------------------------
Note: Test 1 uses the values 1, 2 and 3, so the answer is 3
even though there are 6 numbers. Tests 2 and 3 use a single
distinct value each.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Frequency array as a "seen" marker
- Counting with a second pass
- Small value range trick (values are tiny, so an array of
  size 101 can remember everything)

------------------------------------------------------------
DIFFICULTY: 3/10  (~ Codeforces 800)

------------------------------------------------------------
OPTIONAL HINT:
This is Day 31's frequency array again. While reading,
mark seen[value] = 1. Afterwards, count how many slots from
1 to 100 are marked.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-36_CountDistinct.c

COMMIT MESSAGE:
"Add Day 36 - Count Distinct"

============================================================
*/

#include <stdio.h>

int main() 
{
    int t;
    if(scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        int i,n,val,seen[105] = {0},count=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&val);
            seen[val] = 1;
        }
        for(i=1;i<105;i++)
        {
            if(seen[i] == 1)
                count++;
        }
        printf("%d\n",count);
        t--;
    }
}
