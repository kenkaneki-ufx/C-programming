/*
============================================================
Day 27
============================================================

PROBLEM NAME:
Character Count

------------------------------------------------------------
Statement: You are given a word consisting of lowercase
English letters only. Count how many vowels and how many
consonants it has. For this problem the vowels are exactly:
a, e, i, o, u. Every other letter is a consonant (so 'y' is a
consonant here).
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each of the next t lines contains one
word (1 <= length <= 100, lowercase letters only).

OUTPUT:
For each test case print two integers: the number of vowels
and the number of consonants, separated by a space.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= word length <= 100
- Lowercase letters only

------------------------------------------------------------
SAMPLE INPUT:
3
hello
rhythm
aeiou

SAMPLE OUTPUT:
2 3
0 6
5 0

------------------------------------------------------------
Note: "hello" has vowels e, o and consonants h, l, l.
"rhythm" has no vowels at all (y does not count here) and 6
consonants. "aeiou" is all vowels.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Traversing a char array until '\0'
- Membership check against a small set of characters
- Two counters in one loop

------------------------------------------------------------
DIFFICULTY: 2/10  (~ Codeforces 700)

------------------------------------------------------------
OPTIONAL HINT:
Loop with for (i = 0; word[i] != '\0'; i++). Compare each
character against the five vowels with == or with a long
condition. Everything else is a consonant.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-27_CharacterCount.c

COMMIT MESSAGE:
"Add Day 27 - Character Count"

============================================================
*/

#include <stdio.h>

int main() 
{
    int t;
    if (scanf("%d",&t) != 1) return 0;
    while(t>0)
    {
        int i,vowel=0,consonant=0;
        char str[100];
        scanf("%s",str);
        for(i=0;str[i] != '\0'; i++)
        {
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
                vowel++;
            else
                consonant++;
        }
        printf("%d %d\n",vowel,consonant);
        t--;
    }
    return 0;
}
