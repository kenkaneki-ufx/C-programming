/* ============================================================
   DAILY CODING TASK - DAY 14 (Strings - a little tricky)
   ============================================================
   QUESTION: How do you reverse a string and check
            for palindromes?
   TASK (think before you code):
   1. Read a string from the user (example: "level")
   2. Copy it into ANOTHER array in reverse order and
      print both (original and reversed)
   3. Check if it is a PALINDROME (same forwards and
      backwards - "level" and "madam" are palindromes)
      and print "Palindrome" or "Not a palindrome"
   BONUS (only if you feel ready - skip if not!):
   Ignore spaces and uppercase/lowercase. Check if
   "Never odd or even" is a palindrome.
   ============================================================ */
#include <stdio.h>
#include <string.h>
void main() 
{
   char temp,str[10],rev[10];
   printf("Enter the string: ");
   scanf("%s",str);
   int i,len=strlen(str);
   strcpy(rev,str);
   for( i = 0; i < len/2; i++)
   {
      temp = rev[i];
      rev[i] = rev[len-i-1];
      rev[len-i-1] = temp;
   }
   printf("The original word is: %s\n",str);
   printf("The reversed word is: %s\n",rev);
   if(strcmp(str,rev) == 0)
      printf("'%s' is Palindrome..\n",str);
   else
      printf("'%s' is not Palindrome..\n",str);
   
      
   // BONUS Task ->
   char line[] = "Never odd or even";
   char clean[20], rev_clean[20];
   int j = 0;
   for(i = 0; line[i] != '\0'; i++)
   {
      if(line[i] != ' ')
      {
         if(line[i] >= 'A' && line[i] <= 'Z')
            clean[j] = line[i] + 32;
         else
            clean[j] = line[i];
         j++;
      }
   }
   clean[j] = '\0';
   
   strcpy(rev_clean, clean);
   len = strlen(clean);
   for(i = 0; i < len/2; i++)
   {
      temp = rev_clean[i];
      rev_clean[i] = rev_clean[len-i-1];
      rev_clean[len-i-1] = temp;
   }
   
   printf("\nOriginal: '%s'\n", line);
   printf("Cleaned:  '%s'\n", clean);
   printf("Reversed: '%s'\n", rev_clean);
   
   if(strcmp(clean, rev_clean) == 0)
      printf("'%s' is a Palindrome!\n", line);
   else
      printf("'%s' is not a Palindrome.\n", line);
}
