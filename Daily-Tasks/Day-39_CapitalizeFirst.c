/*
============================================================
Day 39
============================================================

PROBLEM NAME:
Capitalize First

------------------------------------------------------------
Statement: You are given a word of lowercase English
letters. Print the same word but with its FIRST letter
changed to the UPPERCASE version. The rest of the word must
stay exactly the same.
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each of the next t lines contains one
word (1 <= length <= 100, lowercase letters only).

OUTPUT:
For each test case print the word with its first letter in
uppercase.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= word length <= 100
- Lowercase letters only

------------------------------------------------------------
SAMPLE INPUT:
3
hello
code
a

SAMPLE OUTPUT:
Hello
Code
A

------------------------------------------------------------
Note: Only the very first character changes; everything else
is copied as is.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Character arithmetic in C (lowercase -> uppercase)
- Modifying and printing a char array
- ASCII relationship between cases

------------------------------------------------------------
DIFFICULTY: 2/10  (~ Codeforces 700)

------------------------------------------------------------
OPTIONAL HINT:
In ASCII, an uppercase letter is exactly 32 less than its
lowercase version: word[0] - 32 gives the uppercase letter
(when word[0] is lowercase). Or use toupper() from
ctype.h if you prefer.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-39_CapitalizeFirst.c

COMMIT MESSAGE:
"Add Day 39 - Capitalize First"

============================================================
*/

#include <stdio.h>

int main() 
{
    int t;
    if(scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        char word[100];
        scanf("%s",word); 
        word[0]-=32;
        printf("%s\n",word);
        t--;
    }
    return 0;
}
