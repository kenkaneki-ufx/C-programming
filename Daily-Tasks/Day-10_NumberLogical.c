/* ============================================================
   DAILY CODING TASK - DAY 10 (Numbers - a little tricky)
   ============================================================
   QUESTION: What is a palindrome number?
   TASK (think before you code):
   1. Read a number N (example: 121)
   2. Reverse it using a loop
   3. If the reversed number equals N, print "Palindrome"
   4. Also check if N is an ARMSTRONG number:
      153 = 1^3 + 5^3 + 3^3 (cube each digit, add them)
      If yes, print "Armstrong"
   BONUS (only if you feel ready - skip if not!):
   Print all 3-digit Armstrong numbers (100 to 999).
   ============================================================ */
#include <stdio.h>
void main() 
{
   int num,n,digit,rev=0;
   printf("Enter a number: ");
   scanf("%d",&num);
   // Palindrome number ->
      n = num;
   while (n != 0)
   {
      digit = n%10;
      rev = rev*10+digit;
      n /= 10;
   }
   if (n == num)
      printf("\n%d is Palindrome", num);
   else 
      printf("\n%d is not Palindrome", num);
      
   // Armstrong number ->
   n = num;
   int sum = 0;
   while (n != 0)
   {
      digit = n%10;
      sum += digit*digit*digit;
      n /= 10;
   }
   if (sum == num)
      printf("\n%d is Armstrong", num);
   else 
      printf("\n%d is not Armstrong", num);
   // BONUS Task ->
   printf("\n\n3-digit Armstrong numbers.\n");
   for (num = 100; num <= 999; num++)
   {
      sum = 0;
      n = num;
      while (n != 0)
      {
         digit = n%10;
         sum += digit*digit*digit;
         n /= 10;
      }
      if (sum == num)
         printf("%d ", num);
   }
   
}
