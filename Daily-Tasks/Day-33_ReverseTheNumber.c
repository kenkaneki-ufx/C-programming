/*
============================================================
Day 33
============================================================

PROBLEM NAME:
Reverse The Number

------------------------------------------------------------
Statement: You are given a positive integer n. Print the
number obtained by reversing its digits. Leading zeros in the
reversed number disappear automatically (for example 1000
becomes 1).
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each of the next t lines contains a
single integer n (1 <= n <= 10^9).

OUTPUT:
For each test case print the reversed number on its own line.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= n <= 10^9

------------------------------------------------------------
SAMPLE INPUT:
4
123
1000
7
98765

SAMPLE OUTPUT:
321
1
7
56789

------------------------------------------------------------
Note: 1000 reversed is 0001, which is just 1. A single digit
stays the same.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Digit extraction with % 10 and / 10
- Building a number in a loop (r = r*10 + digit)
- Edge case: trailing zeros

------------------------------------------------------------
DIFFICULTY: 2/10  (~ Codeforces 700)

------------------------------------------------------------
OPTIONAL HINT:
This is the mirror of Day 25: pull the last digit with
n % 10, then grow the answer with r = r*10 + digit, then
shrink n with n / 10. Stop when n hits 0.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-33_ReverseTheNumber.c

COMMIT MESSAGE:
"Add Day 33 - Reverse The Number"

============================================================
*/

#include <stdio.h>

int main() 
{
    int t;
    if(scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        int n,rev=0;
        scanf("%d",&n);
        for(int i=n; i!=0;i/=10)
            rev = rev*10 + i%10;
        printf("%d\n",rev);
        t--;
    }
}
