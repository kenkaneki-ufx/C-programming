/*
============================================================
SINGLY LINKED LIST - ALL OPERATIONS
============================================================
DSA Test Preparation - Complete Reference Program

OPERATIONS INCLUDED:
1. Create (Insert at beginning, end, position)
2. Traverse (Display all elements)
3. Insert at Beginning
4. Insert at End
5. Insert at Position
6. Delete from Beginning
7. Delete from End
8. Delete by Value
9. Delete at Position
10. Search
11. Count nodes
12. Reverse
13. Display
============================================================
*/

#include <stdio.h>
#include <stdlib.h>

// ============================================
// NODE STRUCTURE
// ============================================
struct Node {
    int data;
    struct Node* next;
};

// Global start pointer
struct Node* start = NULL;

// ============================================
// 1. CREATE NEW NODE
// ============================================
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// ============================================
// 2. INSERT AT BEGINNING
// ============================================
void insertAtBeginning(int value)
{
    struct Node* newNode = createNode(value);
    newNode->next = start;
    start = newNode;
    printf("Inserted %d at beginning\n", value);
}

// ============================================
// 3. INSERT AT END
// ============================================
void insertAtEnd(int value)
{
    struct Node* newNode = createNode(value);
    
    if (start == NULL)
    {
        start = newNode;
        printf("Inserted %d at end (first element)\n", value);
        return;
    }
    
    struct Node* ptr = start;
    while (ptr->next != NULL) 
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    printf("Inserted %d at end\n", value);
}

// ============================================
// 4. INSERT AT POSITION
// ============================================
void insertAtPosition(int value, int position) 
{
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }
    
    if (position == 0) {
        insertAtBeginning(value);
        return;
    }
    
    struct Node* newNode = createNode(value);
    struct Node* ptr = start;
    
    for (int i = 0; i < position - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    
    if (ptr == NULL) {
        printf("Position %d out of bounds!\n", position);
        free(newNode);
        return;
    }
    
    newNode->next = ptr->next;
    ptr->next = newNode;
    printf("Inserted %d at position %d\n", value, position);
}

// ============================================
// 5. DELETE FROM BEGINNING
// ============================================
void deleteFromBeginning() {
    if (start == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    struct Node* temp = start;
    start = start->next;
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}

// ============================================
// 6. DELETE FROM END
// ============================================
void deleteFromEnd() {
    if (start == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    if (start->next == NULL) {
        printf("Deleted %d from end (last element)\n", start->data);
        free(start);
        start = NULL;
        return;
    }
    
    struct Node* ptr = start;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    
    printf("Deleted %d from end\n", ptr->next->data);
    free(ptr->next);
    ptr->next = NULL;
}

// ============================================
// 7. DELETE BY VALUE
// ============================================
void deleteByValue(int value) {
    if (start == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    // If start contains the value
    if (start->data == value) {
        struct Node* temp = start;
        start = start->next;
        printf("Deleted %d (found at beginning)\n", value);
        free(temp);
        return;
    }
    
    // Search for the value
    struct Node* ptr = start;
    while (ptr->next != NULL && ptr->next->data != value) {
        ptr = ptr->next;
    }
    
    if (ptr->next == NULL) {
        printf("Value %d not found in list!\n", value);
        return;
    }
    
    struct Node* temp = ptr->next;
    ptr->next = temp->next;
    printf("Deleted %d from list\n", value);
    free(temp);
}

// ============================================
// 8. DELETE AT POSITION
// ============================================
void deleteAtPosition(int position) {
    if (start == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }
    
    if (position == 0) {
        deleteFromBeginning();
        return;
    }
    
    struct Node* ptr = start;
    for (int i = 0; i < position - 1 && ptr->next != NULL; i++) {
        ptr = ptr->next;
    }
    
    if (ptr->next == NULL) {
        printf("Position %d out of bounds!\n", position);
        return;
    }
    
    struct Node* temp = ptr->next;
    ptr->next = temp->next;
    printf("Deleted %d from position %d\n", temp->data, position);
    free(temp);
}

// ============================================
// 9. SEARCH ELEMENT
// ============================================
void search(int value) {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* ptr = start;
    int position = 0;
    
    while (ptr != NULL) {
        if (ptr->data == value) {
            printf("Found %d at position %d\n", value, position);
            return;
        }
        ptr = ptr->next;
        position++;
    }
    
    printf("Value %d not found in list!\n", value);
}

// ============================================
// 10. COUNT NODES
// ============================================
void countNodes() {
    int count = 0;
    struct Node* ptr = start;
    
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    
    printf("Total nodes: %d\n", count);
}

// ============================================
// 11. REVERSE LIST
// ============================================
void reverseList() {
    if (start == NULL || start->next == NULL) {
        printf("List is empty or has only one element. Nothing to reverse.\n");
        return;
    }
    
    struct Node* prev = NULL;
    struct Node* ptr = start;
    struct Node* next = NULL;
    
    while (ptr != NULL) {
        next = ptr->next;  // Save next
        ptr->next = prev;  // Reverse link
        prev = ptr;        // Move prev forward
        ptr = next;        // Move ptr forward
    }
    
    start = prev;
    printf("List reversed successfully!\n");
}

// ============================================
// 12. DISPLAY LIST
// ============================================
void displayList() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* ptr = start;
    printf("List: ");
    while (ptr != NULL) {
        printf("%d", ptr->data);
        if (ptr->next != NULL)
            printf(" -> ");
        ptr = ptr->next;
    }
    printf(" -> NULL\n");
}

// ============================================
// 13. FREE ENTIRE LIST
// ============================================
void freeList() {
    struct Node* ptr = start;
    struct Node* next;
    
    while (ptr != NULL) {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
    
    start = NULL;
    printf("List freed from memory.\n");
}

// ============================================
// MENU DISPLAY
// ============================================
void displayMenu() {
    printf("\n");
    printf("========================================\n");
    printf("   SINGLY LINKED LIST - ALL OPERATIONS\n");
    printf("========================================\n");
    printf("1.  Insert at Beginning\n");
    printf("2.  Insert at End\n");
    printf("3.  Insert at Position\n");
    printf("4.  Delete from Beginning\n");
    printf("5.  Delete from End\n");
    printf("6.  Delete by Value\n");
    printf("7.  Delete at Position\n");
    printf("8.  Search Element\n");
    printf("9.  Count Nodes\n");
    printf("10. Reverse List\n");
    printf("11. Display List\n");
    printf("12. Free List\n");
    printf("0.  Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

// ============================================
// MAIN FUNCTION
// ============================================
void main() {
    int choice, value, position;
    
    printf("DSA Test Preparation - Singly Linked List\n");
    printf("========================================\n\n");
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                displayList();
                break;
                
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                displayList();
                break;
                
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (0-based): ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                displayList();
                break;
                
            case 4:
                deleteFromBeginning();
                displayList();
                break;
                
            case 5:
                deleteFromEnd();
                displayList();
                break;
                
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                displayList();
                break;
                
            case 7:
                printf("Enter position to delete (0-based): ");
                scanf("%d", &position);
                deleteAtPosition(position);
                displayList();
                break;
                
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
                
            case 9:
                countNodes();
                break;
                
            case 10:
                reverseList();
                displayList();
                break;
                
            case 11:
                displayList();
                break;
                
            case 12:
                freeList();
                break;
                
            case 0:
                freeList();
                printf("Exiting... Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
