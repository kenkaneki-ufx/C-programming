/* ============================================================
   DAILY CODING TASK - DAY 3 (Strings - beginner friendly)
   ============================================================
   QUESTION: Can you store your name in a char array and print it?
   TASK (easy part - no pointers needed!):
   1. Make a string: name[] = "YourName"
   2. Print it using %s
   3. Count its length using strlen() from string.h
   BONUS (only if you feel ready - skip if not!):
   Print your name one character at a time using a loop:
   name[0], name[1], name[2]... and count the letters yourself.
   ============================================================ */
#include <stdio.h>
#include <string.h>
void main() {
   char name[10];
   printf("Enter your name: ");
   scanf("%s",&name);
   printf("Hello %s",name);
   int len = strlen(name);
   printf("\nThe length of your name is: %d",len);
}
