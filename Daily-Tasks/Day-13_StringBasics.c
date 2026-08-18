/* ============================================================
   DAILY CODING TASK - DAY 13 (Strings - beginner friendly)
   ============================================================
   QUESTION: How is a string actually stored in memory?
   TASK (easy part - no pointers needed!):
   1. Make a string: word = "hello";
   2. Print it with %s
   3. Loop through it with word[i] and stop when you
      hit '\0'. Count the VOWELS (a, e, i, o, u)
      and print the count.
   BONUS (only if you feel ready - skip if not!):
   Also count the consonants and print both counts.
   ============================================================ */
#include <stdio.h>
void main() 
{
   char word[20];
   printf("Enter a word: ");
   scanf("%s",word);
   int i=0,vowel=0,consonent=0;
   printf("[ %s ]\n", word);
   while( word[i] != '\0')
   {
      if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u' || word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U')
         vowel++;
      else  // BONUS Task
         consonent++;
      i++;
   }
   printf("\nVowels : %d", vowel);
   printf("\nConsonents : %d", consonent);
}
