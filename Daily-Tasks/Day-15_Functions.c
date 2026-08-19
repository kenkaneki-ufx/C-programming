/*
============================================================
Day 15 — Functions
============================================================
PROBLEM NAME:
Mini Calculator Using Functions
------------------------------------------------------------
GOAL:
Write a C program that uses functions to perform basic 
arithmetic operations through a menu-driven interface.
------------------------------------------------------------
REQUIREMENTS:
1. Create functions for each operation:
   - int add(int a, int b)
   - int subtract(int a, int b)
   - int multiply(int a, int b)
   - float divide(int a, int b)
   - int modulus(int a, int b)
2. Create a function to display the menu:
   - void displayMenu()
3. Create a function to get user choice:
   - int getChoice()
4. Main program flow:
   - Display menu
   - Get user choice
   - Get two numbers from user
   - Call appropriate function
   - Display result
   - Repeat until user chooses exit
5. Handle division by zero gracefully
------------------------------------------------------------
RULES:
- Each operation must be a separate function
- Functions must return the result
- Use appropriate return types (int vs float)
- Do NOT use global variables
- Pass values to functions (pass by value)
------------------------------------------------------------
CONSTRAINTS:
- Numbers can be any integer
- Division should show decimal result
- Modulus only works with integers
- Handle division by zero with error message
------------------------------------------------------------
EXAMPLE RUN:
=== Mini Calculator ===
1. Add
2. Subtract
3. Multiply
4. Divide
5. Modulus
6. Exit
Choose operation (1-6): 1
Enter first number: 15
Enter second number: 7
Result: 15 + 7 = 22
Choose operation (1-6): 4
Enter first number: 20
Enter second number: 0
Error: Division by zero!
Choose operation (1-6): 6
Goodbye!
------------------------------------------------------------
CONCEPTS PRACTICED:
- Function declaration
- Function definition
- Function calling
- Parameters and arguments
- Return values
- Return types (int vs float)
- Menu-driven programs
- Modular code structure
------------------------------------------------------------
DIFFICULTY: 3/10
------------------------------------------------------------
FILENAME SUGGESTION:
Day-15_Functions.c
COMMIT MESSAGE:
"Add mini calculator using functions"
============================================================
*/
#include <stdio.h>
int add(int a, int b) 
{
   return a+b;    
}
int subtract(int a, int b) 
{
   return a-b;
}
int multiply(int a, int b) 
{
   return a*b;
}
float divide(int a, int b) 
{  
   return a/(float)b;
}
int modulus(int a, int b) 
{
   return a%b;    
}
void displayMenu() 
{
   printf("\n=== Mini Calculator ===\n");
      printf("1. Add\n");
      printf("2. Subtract\n");
      printf("3. Multiply\n");
      printf("4. Divide\n");
      printf("5. Modulus\n");
      printf("6. Exit\n");
   }
   
int getChoice() 
{
   int choice;
   printf("\nChoose operation (1-6): ");
   scanf("%d",&choice);
   return choice;
}
void main() 
{   
   int choice,num1,num2;      // 1. Declare variables
   
   while (choice != 6)        // 2. Create loop for menu
   {
      displayMenu();          // 3. Display menu
      
      choice = getChoice();    // 4. Get user choice
      
      if(choice == 6)         // 5. If choice is 6, exit
      {   
         printf("Goodbye!.");
         break;
      }
      printf("Enter first number: ");// 6. Get two numbers
      scanf("%d",&num1);
      printf("Enter second number: ");
      scanf("%d",&num2);
      
      if (choice==1)
         printf("\n[ %d + %d = %d ]\n", num1, num2, add(num1,num2));
      else if (choice==2)
         printf("\n[ %d - %d = %d ]\n", num1, num2, subtract(num1,num2));
      else if (choice==3)
         printf("\n[ %d * %d = %d ]\n", num1, num2, multiply(num1,num2));
      else if (choice==4)
      {  
         if(num2 == 0)
            printf("\nError: Division by zero!");
         else
            printf("\n[ %d / %d = %.2f ]\n", num1, num2, divide(num1,num2));
      }
      else if (choice==5)
         printf("\n[ %d mod %d = %d ]\n", num1, num2, modulus(num1,num2));
      else 
         printf("\nInvalid choice.");
   }
}
