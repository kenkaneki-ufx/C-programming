/* ============================================================
   DAILY CODING TASK - DAY 6 (Structures - beginner friendly)
   ============================================================
   QUESTION: Can you store a student's details in ONE variable?
   TASK (easy part - no pointers needed!):
   1. Create a struct Student with three fields:
      name (char array), roll (int), marks (int)
   2. Fill it with your own details (use strcpy for the name)
   3. Print all three fields
   BONUS (only if you feel ready - skip if not!):
   Make an array of 3 students and print all of them in a loop.
   ============================================================ */
#include <stdio.h>
#include <string.h>
/* A struct is a BLUEPRINT for a custom type.
   It groups several related values into ONE variable.
   Think of it as a single paper form with 3 boxes to fill. */
struct Student {
    char name[50];   // box 1: name as a string
    int roll;        // box 2: roll number
    int marks;       // box 3: marks out of 100
};
void main() {
    /* --- TASK: one student --- */
    // Declare ONE variable of type struct Student.
    // It now holds 3 boxes inside it (name, roll, marks).
    struct Student s1;
    // Fill box 1: strcpy because we CANNOT do  s1.name = "...";
    // (arrays can't be assigned with = , only copied element by element)
    strcpy(s1.name, "Ken");
    s1.roll  = 101;    // fill box 2 with . (dot) operator
    s1.marks = 92;     // fill box 3
    printf("=== Task: one student ===\n");
    printf("Name : %s\n", s1.name);    // . is how you reach INSIDE a struct
    printf("Roll : %d\n", s1.roll);
    printf("Marks: %d\n", s1.marks);
    /* --- BONUS: array of 3 students, printed in a loop --- */
    struct Student batch[3];   // 3 forms side by side
    strcpy(batch[0].name, "Ken");
    batch[0].roll = 101;  batch[0].marks = 92;
    strcpy(batch[1].name, "Arya");
    batch[1].roll = 102;  batch[1].marks = 88;
    strcpy(batch[2].name, "Sam");
    batch[2].roll = 103;  batch[2].marks = 95;
    // batch[i] = the i-th student form, .field = one box inside it
    printf("\n=== Bonus: array of students ===\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s (roll %d) got %d marks\n",
               i + 1, batch[i].name, batch[i].roll, batch[i].marks);
    }
}
