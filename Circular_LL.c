#include <stdio.h>
#include <stdlib.h>
struct node
{
   int data;
   struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
int main(int argc, char *argv[])
{
   int option;
   do
   {
      printf("\n\n *****MAIN MENU (CIRCULAR LINKED LIST)*****");
      printf("\n 1: Create a list");
      printf("\n 2: Display the list");
      printf("\n 3: Add a node at the beginning");
      printf("\n 4: Add a node at the end");
      printf("\n 5: Delete a node from the beginning");
      printf("\n 6: Delete a node from the end");
      printf("\n 7: Delete a node after a given node");
      printf("\n 8: Delete the entire list");
      printf("\n 9: EXIT");
      printf("\n\n Enter your option: ");
      scanf("%d", &option);
      switch (option)
      {
      case 1:
         start = create_ll(start);
         printf("\n LINKED LIST CREATED");
         break;
      case 2:
         start = display(start);
         break;
      case 3:
         start = insert_beg(start);
         break;
      case 4:
         start = insert_end(start);
         break;
      case 5:
         start = delete_beg(start);
         break;
      case 6:
         start = delete_end(start);
         break;
      case 7:
         start = delete_after(start);
         break;
      case 8:
         start = delete_list(start);
         printf("\n LINKED LIST DELETED");
         break;
      case 9:
         printf("\n Exiting...");
         break;
      default:
         printf("\nInvalid Option.");
         break;
      }
   }
   while (option != 9);
   return 0;
}

struct node *create_ll(struct node *start)
{
   struct node *new_node, *ptr;
   int num;
   printf("\n Enter -1 to end");
   printf("\n Enter the data :");
   scanf("%d", &num);
   while (num != -1)
   {
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->data = num;
      if (start == NULL)
      {
         new_node->next = new_node;  /* Points to itself in circular LL */
         start = new_node;
      }
      else
      {
         ptr = start;
         while (ptr->next != start)
         {
            ptr = ptr->next;
         }
         ptr->next = new_node;
         new_node->next = start;  /* New node points back to start */
      }
      printf("\n Enter the data:");
      scanf("%d", &num);
   }
   return start;
}

struct node *display(struct node *start)
{
   struct node *ptr;
   if (start == NULL)
   {
      printf("\n List is empty");
      return start;
   }
   ptr = start;
   printf("\n List: ");
   do
   {
      printf("%d ", ptr->data);
      ptr = ptr->next;
   } while (ptr != start);
   printf("\n");
   return start;
}

struct node *insert_beg(struct node *start)
{
   struct node *new_node, *ptr;
   int num;
   printf("\n Enter the data:");
   scanf("%d", &num);
   new_node = (struct node *)malloc(sizeof(struct node));
   new_node->data = num;
   if (start == NULL)
   {
      new_node->next = new_node;
      start = new_node;
   }
   else
   {
      ptr = start;
      while (ptr->next != start)
      {
         ptr = ptr->next;
      }
      ptr->next = new_node;
      new_node->next = start;
      start = new_node;
   }
   return start;
}

struct node *insert_end(struct node *start)
{
   struct node *ptr, *new_node;
   int num;
   printf("\n Enter the data:");
   scanf("%d", &num);
   new_node = (struct node *)malloc(sizeof(struct node));
   new_node->data = num;
   if (start == NULL)
   {
      new_node->next = new_node;
      start = new_node;
   }
   else
   {
      ptr = start;
      while (ptr->next != start)
      {
         ptr = ptr->next;
      }
      ptr->next = new_node;
      new_node->next = start;
   }
   return start;
}

struct node *delete_beg(struct node *start)
{
   struct node *ptr, *last;
   if (start == NULL)
   {
      printf("\n List is empty");
      return start;
   }
   if (start->next == start)
   {
      printf("\n Deleted %d", start->data);
      free(start);
      start = NULL;
   }
   else
   {
      ptr = start;
      last = start;
      while (last->next != start)
      {
         last = last->next;
      }
      last->next = start->next;
      printf("\n Deleted %d", start->data);
      free(start);
      start = last->next;
   }
   return start;
}

struct node *delete_end(struct node *start)
{
   struct node *ptr, *preptr;
   if (start == NULL)
   {
      printf("\n List is empty");
      return start;
   }
   if (start->next == start)
   {
      printf("\n Deleted %d", start->data);
      free(start);
      start = NULL;
   }
   else
   {
      ptr = start;
      while (ptr->next != start)
      {
         preptr = ptr;
         ptr = ptr->next;
      }
      preptr->next = start;
      printf("\n Deleted %d", ptr->data);
      free(ptr);
   }
   return start;
}

struct node *delete_after(struct node *start)
{
   struct node *ptr, *temp;
   int val;
   printf("\n Enter the value after which the node has to be deleted: ");
   scanf("%d", &val);
   if (start == NULL)
   {
      printf("\n List is empty");
      return start;
   }
   ptr = start;
   do
   {
      if (ptr->data == val)
      {
         if (ptr->next == start)
         {
            printf("\n No node exists after %d", val);
         }
         else
         {
            temp = ptr->next;
            ptr->next = temp->next;
            printf("\n Deleted %d", temp->data);
            free(temp);
         }
         return start;
      }
      ptr = ptr->next;
   } while (ptr != start);
   printf("\n Value %d not found in list", val);
   return start;
}

struct node *delete_list(struct node *start)
{
   struct node *ptr;
   if (start == NULL)
   {
      printf("\n List is already empty");
      return start;
   }
   do
   {
      ptr = start;
      start = start->next;
      free(ptr);
   } while (start != NULL && start != ptr->next);
   start = NULL;
   return start;
}
