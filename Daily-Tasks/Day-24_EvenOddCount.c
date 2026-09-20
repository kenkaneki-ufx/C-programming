/*
============================================================
Day 24
============================================================

PROBLEM NAME:
Even-Odd Count

------------------------------------------------------------
Statement: You are given n integers. Count how many of them
are even and how many are odd.
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each test case consists of two lines:
- the first line contains an integer n (1 <= n <= 1000);
- the second line contains n integers a_1, a_2, ..., a_n
  (1 <= a_i <= 1000).

OUTPUT:
For each test case print two integers on one line: the count
of even numbers and the count of odd numbers, separated by a
space.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= n <= 1000
- 1 <= a_i <= 1000

------------------------------------------------------------
SAMPLE INPUT:3
5
1 2 3 4 5

1
8

4
2 4 6 7

SAMPLE OUTPUT:
2 3
1 0
3 1

------------------------------------------------------------
Note: In the first test case 2 and 4 are even, 1, 3, 5 are
odd. In the second test case 8 is the only number and it is
even. In the third test case 2, 4, 6 are even and 7 is odd.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Judge-style input/output (read silently, print exactly)
- Multiple test cases in one run
- The % operator
- Simple counting

------------------------------------------------------------
DIFFICULTY: 1/10  (~ Codeforces 600)

------------------------------------------------------------
OPTIONAL HINT:
A number is even when number % 2 == 0. Two counters, one
loop, done.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-24_EvenOddCount.c

COMMIT MESSAGE:
"Add Day 24 - Even-Odd Count"

============================================================
*/

#include <stdio.h>

void main() 
{
    int odd=0,even=0,ar[20],i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
		if(ar[i]%2==0)
			even++;
		else
			odd++;
	}
	printf("%d %d",even,odd);
}
