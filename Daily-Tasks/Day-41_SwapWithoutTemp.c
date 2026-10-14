/*
============================================================
Day 41
============================================================

PROBLEM NAME:
Swap Without a Temporary

------------------------------------------------------------
Statement: You are given two integers x and y. Swap their
values and print the result — but you are NOT allowed to use
a third temporary variable. Use the classic arithmetic trick:
after the three steps a = a + b; b = a - b; a = a - b; the
two values have swapped.
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each of the next t lines contains two
integers x and y (0 <= x, y <= 10^9).

OUTPUT:
For each test case print the two values after swapping, on
one line, separated by a space.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 0 <= x, y <= 10^9

------------------------------------------------------------
SAMPLE INPUT:
3
3 7
0 1000000000
5 5

SAMPLE OUTPUT:
7 3
1000000000 0
5 5

------------------------------------------------------------
Note: Test 1: 3 and 7 become 7 and 3. Test 2: the sum can
reach 10^9 + 0 which still fits in a long long (and in this
case even in int, but think about when it would NOT).
Test 3: equal values swap to themselves.

------------------------------------------------------------
CONCEPTS PRACTICED:
- The arithmetic swap trick
- Thinking about overflow (sum of two values)
- Using long long when values get big

------------------------------------------------------------
DIFFICULTY: 3/10  (~ Codeforces 800)

------------------------------------------------------------
OPTIONAL HINT:
Read both numbers into long long variables. Apply the three
steps a = a + b; b = a - b; a = a - b in exactly that order.
Convince yourself on paper WHY each step leaves the right
value behind.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-41_SwapWithoutTemp.c

COMMIT MESSAGE:
"Add Day 41 - Swap Without a Temporary"

============================================================
*/

#include <stdio.h>

int main() 
{
    int t;
    if(scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        long long int x,y;
        scanf("%lld %lld",&x,&y);
        x = x+y;
        y = x-y;
        x = x-y;
        printf("%lld %lld\n",x,y);
        t--;
    }
    return 0;
}
