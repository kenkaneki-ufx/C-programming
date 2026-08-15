/* ============================================================
   DAILY CODING TASK - DAY 6 (Structures - beginner friendly)
   ============================================================
   QUESTION: Can you store a student's details in ONE variable?
   TASK (easy part - no pointers needed!):
   1. Create a struct Student with three fields:
      name (char array), roll (int), marks (int)
   2. Fill it with your own details (use strcpy for the name)
   3. Print all three fields
      Make an array of 3 students and print all of them in a loop.
   ============================================================ */
#include <stdio.h>
#include <string.h>
struct Student 
{
   char name[50];
   int roll;
   int marks;
};
void main() 
{
   struct Student s1;
   strcpy(s1.name, "Aryan");
   s1.roll  = 100, s1.marks = 79;
   printf("=== one student ===\n");
   printf("Name : %s\n", s1.name);
   printf("Roll : %d\n", s1.roll);
   printf("Marks: %d\n", s1.marks);
   struct Student S[3];
   strcpy(S[0].name, "Ansh");
   S[0].roll = 101,  S[0].marks = 92;
   strcpy(S[1].name, "Aman");
   S[1].roll = 102,  S[1].marks = 88;
   strcpy(S[2].name, "Ankit");
   S[2].roll = 103,  S[2].marks = 95;
   
   printf("\n=== array of students ===\n");
   for (int i = 0; i < 3; i++)
      printf("%d. %s (roll %d) got %d marks\n",i + 1, S[i].name, S[i].roll, S[i].marks);
}
