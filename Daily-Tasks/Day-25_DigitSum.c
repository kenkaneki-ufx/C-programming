/*
============================================================
Day 25
============================================================

PROBLEM NAME:
Digit Sum

------------------------------------------------------------
Statement: For a positive integer n, compute the sum of its
digits. Print the digit sum, and print "YES" if the digit sum
is divisible by 3, otherwise print "NO".
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each of the next t lines contains a
single integer n (1 <= n <= 10^9).

OUTPUT:
For each test case print the digit sum and "YES" if it is
divisible by 3, or "NO" if it is not, on one line.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= n <= 10^9

------------------------------------------------------------
SAMPLE INPUT:
3
123
9999
10

SAMPLE OUTPUT:
6 YES
36 YES
1 NO

------------------------------------------------------------
Note: 123 has digits 1+2+3 = 6, and 6 is divisible by 3.
9999 has digits 9+9+9+9 = 36, divisible by 3. 10 has digit
sum 1, not divisible by 3.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Extracting digits with % 10 and / 10
- While loops
- Divisibility check
- long long comfort with big inputs

------------------------------------------------------------
DIFFICULTY: 1/10  (~ Codeforces 700)

------------------------------------------------------------
OPTIONAL HINT:
n % 10 gives the last digit; n / 10 removes the last digit.
Repeat until n becomes 0.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-25_DigitSum.c

COMMIT MESSAGE:
"Add Day 25 - Digit Sum"

============================================================
*/

#include <stdio.h>

void main() 
{
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        int n,a,sum=0;
        scanf("%d",&n);
        while (n!=0)
        {
            a=n%10;
            sum+=a;
            n/=10;
        }
        if(sum%3==0)
            printf("%d YES\n",sum);
        else
            printf("%d NO\n",sum);
        t--;
    }
}
