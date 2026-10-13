/*
============================================================
Day 40
============================================================

PROBLEM NAME:
Right Angle Triangle

------------------------------------------------------------
Statement: You are given three positive integers a, b, c.
Decide whether they can be the sides of a RIGHT-ANGLE
triangle. This is true exactly when one of the three numbers
squared equals the sum of the squares of the other two
(Pythagoras). Print "YES" or "NO".
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each of the next t lines contains
three integers a, b, c (1 <= a, b, c <= 1000).

OUTPUT:
For each test case print "YES" if the three numbers form a
right-angle triangle, otherwise "NO".

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= a, b, c <= 1000

------------------------------------------------------------
SAMPLE INPUT:
4
3 4 5
5 12 13
1 2 3
6 8 10

SAMPLE OUTPUT:
YES
YES
NO
YES

------------------------------------------------------------
Note: Test 1: 3^2 + 4^2 = 9 + 16 = 25 = 5^2. Test 2:
25 + 144 = 169 = 13^2. Test 3: 1 + 4 = 5 which is not 9, and
no other arrangement works either. Test 4: 36 + 64 = 100 =
10^2 — the hypotenuse does not have to come last in the
input.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Checking all cases (which side is the hypotenuse?)
- Squares and comparisons
- Avoiding floating point (stay in integers)

------------------------------------------------------------
DIFFICULTY: 3/10  (~ Codeforces 800)

------------------------------------------------------------
OPTIONAL HINT:
You do not know which side is the hypotenuse, so check all
three possibilities: a*a == b*b + c*c, or b*b == a*a + c*c,
or c*c == a*a + b*b. With a, b, c <= 1000 the squares fit
easily in int, but using long long is good practice.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-40_RightAngleTriangle.c

COMMIT MESSAGE:
"Add Day 40 - Right Angle Triangle"

============================================================
*/

#include <stdio.h>

int main() 
{
    int t;
    if(scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if (a*a+b*b == c*c)
            printf("YES\n");
        else if (a*a+c*c == b*b)
            printf("YES\n");
        else if (c*c+b*b == a*a)
            printf("YES\n");
        else
            printf("NO\n");
        t--;
    }
    return 0;
}
