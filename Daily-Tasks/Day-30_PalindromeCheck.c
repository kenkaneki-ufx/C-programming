/*
============================================================
Day 30
============================================================

PROBLEM NAME:
Palindrome Check

------------------------------------------------------------
Statement: A word is a PALINDROME if it reads the same
forwards and backwards (for example "level" or "noon").
You are given a word of lowercase letters. Print "YES" if it
is a palindrome, otherwise "NO". Also print the MINIMUM
number of letter changes needed to turn it into a palindrome
(0 if it already is one).

Changing one letter means replacing it with any other
lowercase letter.
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each of the next t lines contains one
word (1 <= length <= 100, lowercase letters only).

OUTPUT:
For each test case print one line: "YES 0" if the word is a
palindrome, otherwise "NO c" where c is the minimum number
of changes needed.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= word length <= 100
- Lowercase letters only

------------------------------------------------------------
SAMPLE INPUT:
4
level
abc
noon
abca

SAMPLE OUTPUT:
YES 0
NO 1
YES 0
NO 1

------------------------------------------------------------
Note: "level" and "noon" are already palindromes. "abc":
the pair (a, c) mismatches, one change (for example turning
it into "cbc") is enough. "abca": the outer pair (a, a)
matches, the inner pair (b, c) mismatches, so one change is
enough, for example "abba".

------------------------------------------------------------
CONCEPTS PRACTICED:
- Two-pointer pairing (i and n-1-i)
- Counting mismatched pairs
- palindromes review in judge format

------------------------------------------------------------
DIFFICULTY: 3/10  (~ Codeforces 800)

------------------------------------------------------------
OPTIONAL HINT:
Compare word[i] with word[n-1-i] for i from 0 to n/2 - 1.
Every mismatched pair needs exactly ONE change to fix (make
the two letters equal). The answer is the number of
mismatched pairs.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-30_PalindromeCheck.c

COMMIT MESSAGE:
"Add Day 30 - Palindrome Check"

============================================================
*/

#include <stdio.h>

int main() 
{
    int t;
    if(scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        int i,n=0,count=0;
        char word[100];
        scanf("%s",word);
        while(word[n] != '\0')
            n++;
        for(i=0;i<n/2;i++)
        {
            if(word[i]!=word[n-1-i])
                count++;
        }
        if(count!=0)
            printf("NO %d\n",count);
        else
            printf("YES 0\n");
        t--;
    }
}
