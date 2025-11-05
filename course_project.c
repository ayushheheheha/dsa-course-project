/*DSA COURSE PROJECT
  AYUSH YADAV (24MIS0295)
  SRIRAM (24MIS0468)
  VAIBHAV KUMAR (24MIS0476)
  VIDHANSHU (24MIS0483)
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int data) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("STEP 1: CREATING A NEW NODE\n");
    printf("-------------------------------------------------------------------------------\n");   
    printf("Allocating memory for new node with data: %d\n", data);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));   
    if (newNode == NULL) {
        printf("ERROR: Memory allocation failed!\n");
        return NULL;
    }    
    printf("Memory allocated successfully at address: %p\n", (void*)newNode);
    printf("Setting node data: %d\n", data);
    newNode->data = data;    
    printf("Initializing next and prev pointers to point to itself\n");
    newNode->next = newNode;
    newNode->prev = newNode;    
    printf("NEW NODE CREATED SUCCESSFULLY!\n");
    printf("   Address: %p\n", (void*)newNode);
    printf("   Data: %d\n", newNode->data);
    printf("   Next: %p (points to itself)\n", (void*)newNode->next);
    printf("   Prev: %p (points to itself)\n", (void*)newNode->prev);    
    return newNode;
}
void displayList(struct Node* head) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("CURRENT LIST STATUS\n");
    printf("-------------------------------------------------------------------------------\n");
    if (head == NULL) {
        printf("The list is EMPTY\n");
        printf("   Head pointer: NULL\n");
        return;
    }    
    printf("Head pointer points to: %p\n", (void*)head);
    printf("List elements (forward traversal): ");    
    struct Node* temp = head;
    int count = 0;
    do {
        printf("%d", temp->data);
        if (temp->next != head) {
            printf(" <-> ");
        }
        temp = temp->next;
        count++;
    } while (temp != head);    
    printf("\n\nVISUAL REPRESENTATION:\n");
    printf("   ");    
    temp = head;
    do {
        printf("+---------+");
        if (temp->next != head) printf("<->");
        temp = temp->next;
    } while (temp != head);    
    printf("\n   ");    
    temp = head;
    do {
        printf("|    %d    |", temp->data);
        if (temp->next != head) printf("   ");
        temp = temp->next;
    } while (temp != head);    
    printf("\n   ");    
    temp = head;
    do {
        printf("+---------+");
        if (temp->next != head) printf("<->");
        temp = temp->next;
    } while (temp != head);    
    printf("\n\nTotal nodes: %d\n", count);
    printf("\nPOINTER CONNECTIONS:\n");
    temp = head;
    do {
        printf("   Node %d: \n", temp->data);
        printf("      Address: %p\n", (void*)temp);
        printf("      Data: %d\n", temp->data);
        printf("      Next -> %p (points to node %d)\n", (void*)temp->next, temp->next->data);
        printf("      Prev <- %p (points to node %d)\n", (void*)temp->prev, temp->prev->data);
        temp = temp->next;
    } while (temp != head);
}
struct Node* insertAtBeginning(struct Node* head, int data) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("INSERTING AT BEGINNING - Data: %d\n", data);
    printf("-------------------------------------------------------------------------------\n");   
    struct Node* newNode = createNode(data);    
    if (head == NULL) {
        printf("\nThe list is empty, new node becomes the head\n");
        printf("Insertion complete! Head points to new node\n");
        return newNode;
    }    
    printf("\nList is not empty. Current head points to node with data: %d\n", head->data);
    printf("\nBEFORE INSERTION - List structure:\n");
    printf("   Last node (%d) -> Head (%d) -> Second node (%d)\n", 
           head->prev->data, head->data, head->next->data);
    printf("\nSTEP 2: UPDATING POINTERS\n");
    struct Node* last = head->prev;
    printf("   Last node is: %d (at address %p)\n", last->data, (void*)last);   
    printf("\n   Updating newNode->next to point to current head (%d)\n", head->data);
    newNode->next = head;    
    printf("   Updating newNode->prev to point to last node (%d)\n", last->data);
    newNode->prev = last;    
    printf("   Updating last->next to point to new node (%d)\n", newNode->data);
    last->next = newNode;    
    printf("   Updating head->prev to point to new node (%d)\n", newNode->data);
    head->prev = newNode;    
    printf("\nINSERTION COMPLETE! New node is now the head\n");
    printf("   New head points to: %p (data: %d)\n", (void*)newNode, newNode->data);    
    return newNode;
}
struct Node* insertAtEnd(struct Node* head, int data) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("INSERTING AT END - Data: %d\n", data);
    printf("-------------------------------------------------------------------------------\n");   
    struct Node* newNode = createNode(data);    
    if (head == NULL) {
        printf("\nThe list is empty, new node becomes the head\n");
        printf("Insertion complete! Head points to new node\n");
        return newNode;
    }    
    printf("\nList is not empty. Current head: %d\n", head->data);
    struct Node* last = head->prev;
    printf("Current last node: %d\n", last->data);    
    printf("\nSTEP 2: UPDATING POINTERS\n");    
    printf("   Setting newNode->next to point to head (%d)\n", head->data);
    newNode->next = head;    
    printf("   Setting newNode->prev to point to current last node (%d)\n", last->data);
    newNode->prev = last;    
    printf("   Updating current last node's next pointer to point to new node\n");
    last->next = newNode;    
    printf("   Updating head's prev pointer to point to new node\n");
    head->prev = newNode;    
    printf("\nINSERTION COMPLETE! New node added at the end\n");
    printf("   New last node: %d\n", newNode->data);    
    return head;
}
struct Node* insertAfter(struct Node* head, int afterData, int data) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("INSERTING AFTER NODE - Insert %d after node with data %d\n", data, afterData);
    printf("-------------------------------------------------------------------------------\n");   
    if (head == NULL) {
        printf("ERROR: List is empty! Cannot insert after specific node.\n");
        return NULL;
    }   
    struct Node* current = head;
    struct Node* targetNode = NULL;    
    printf("\nSTEP 1: SEARCHING FOR NODE WITH DATA %d\n", afterData);
    do {
        printf("   Checking node at %p with data: %d", (void*)current, current->data);
        if (current->data == afterData) {
            printf(" FOUND!\n");
            targetNode = current;
            break;
        }
        printf(" Not matching\n");
        current = current->next;
    } while (current != head);    
    if (targetNode == NULL) {
        printf("ERROR: Node with data %d not found in the list!\n", afterData);
        return head;
    }    
    printf("\nTARGET NODE FOUND:\n");
    printf("   Address: %p\n", (void*)targetNode);
    printf("   Data: %d\n", targetNode->data);
    printf("   Next: %p (points to %d)\n", (void*)targetNode->next, targetNode->next->data);
    printf("   Prev: %p (points to %d)\n", (void*)targetNode->prev, targetNode->prev->data);    
    struct Node* newNode = createNode(data);
    printf("\nSTEP 2: UPDATING POINTERS\n");
    printf("   Current connection: %d -> %d\n", targetNode->data, targetNode->next->data);
    printf("   Setting newNode->next to point to targetNode->next (%d)\n", targetNode->next->data);
    newNode->next = targetNode->next;
    printf("   Setting newNode->prev to point to targetNode (%d)\n", targetNode->data);
    newNode->prev = targetNode;
    printf("   Updating targetNode->next->prev to point to new node\n");
    targetNode->next->prev = newNode;
    printf("   Updating targetNode->next to point to new node\n");
    targetNode->next = newNode;
    printf("\nINSERTION COMPLETE! New node inserted after %d\n", afterData);
    printf("   New connection: %d -> %d -> %d\n", targetNode->data, newNode->data, newNode->next->data);
    return head;
}
struct Node* deleteNode(struct Node* head, int data) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("DELETING NODE - Data: %d\n", data);
    printf("-------------------------------------------------------------------------------\n");   
    if (head == NULL) {
        printf("ERROR: List is empty! Cannot delete.\n");
        return NULL;
    }
    struct Node* current = head;
    struct Node* toDelete = NULL;
    printf("\nSTEP 1: SEARCHING FOR NODE WITH DATA %d\n", data);
    do {
        printf("   Checking node at %p with data: %d", (void*)current, current->data);
        if (current->data == data) {
            printf(" FOUND!\n");
            toDelete = current;
            break;
        }
        printf(" Not matching\n");
        current = current->next;
    } while (current != head);
    if (toDelete == NULL) {
        printf("ERROR: Node with data %d not found in the list!\n", data);
        return head;
    }
    printf("\nNODE TO DELETE FOUND:\n");
    printf("   Address: %p\n", (void*)toDelete);
    printf("   Data: %d\n", toDelete->data);
    printf("   Next: %p (points to %d)\n", (void*)toDelete->next, toDelete->next->data);
    printf("   Prev: %p (points to %d)\n", (void*)toDelete->prev, toDelete->prev->data);
    if (toDelete->next == toDelete && toDelete->prev == toDelete) {
        printf("\nSPECIAL CASE: This is the only node in the list\n");
        printf("   Freeing the node and setting head to NULL\n");
        free(toDelete);
        printf("DELETION COMPLETE! List is now empty\n");
        return NULL;
    }
    printf("\nSTEP 2: UPDATING NEIGHBOR POINTERS\n");
    printf("   Current connections:\n");
    printf("   %d <- %d -> %d\n", toDelete->prev->data, toDelete->data, toDelete->next->data);
    printf("   Updating previous node's next pointer:\n");
    printf("      %d->next was pointing to %d, now pointing to %d\n", 
           toDelete->prev->data, toDelete->data, toDelete->next->data);
    toDelete->prev->next = toDelete->next;
    printf("   Updating next node's prev pointer:\n");
    printf("      %d->prev was pointing to %d, now pointing to %d\n", 
           toDelete->next->data, toDelete->data, toDelete->prev->data);
    toDelete->next->prev = toDelete->prev;
    struct Node* newHead = head;
    if (toDelete == head) {
        printf("\nSPECIAL CASE: Deleting the head node\n");
        printf("   Updating head to point to next node: %d\n", head->next->data);
        newHead = head->next;
    }
    printf("\nSTEP 3: FREEING MEMORY\n");
    printf("   Freeing node at address %p (data: %d)\n", (void*)toDelete, toDelete->data);
    free(toDelete);
    printf("DELETION COMPLETE! Node %d successfully removed\n", data);
    return newHead;
}
void countNodes(struct Node* head) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("COUNTING NODES IN THE LIST\n");
    printf("-------------------------------------------------------------------------------\n");   
    if (head == NULL) {
        printf("The list is EMPTY\n");
        printf("   Total nodes: 0\n");
        return;
    }
    struct Node* temp = head;
    int count = 0;
    printf("Starting count from head node: %d\n", head->data);
    do {
        count++;
        printf("   Node %d: data = %d, address = %p\n", count, temp->data, (void*)temp);
        temp = temp->next;
    } while (temp != head);
    printf("\nTOTAL NODES COUNTED: %d\n", count);
}
void demonstrateTraversal(struct Node* head) {
    printf("\n-------------------------------------------------------------------------------\n");
    printf("DEMONSTRATING TRAVERSAL IN BOTH DIRECTIONS\n");
    printf("-------------------------------------------------------------------------------\n");   
    if (head == NULL) {
        printf("ERROR: List is empty! Cannot demonstrate traversal.\n");
        return;
    }
    printf("Starting from head node: %d\n\n", head->data);
    printf("FORWARD TRAVERSAL (using next pointers):\n");
    struct Node* temp = head;
    int step = 1;
    do {
        printf("   Step %d: Current node = %d, Next node = %d\n", 
               step, temp->data, temp->next->data);
        temp = temp->next;
        step++;
    } while (temp != head);
    printf("   Reached head again! Circular traversal complete.\n\n");
    printf("BACKWARD TRAVERSAL (using prev pointers):\n");
    temp = head->prev; // Start from last node
    step = 1;
    do {
        printf("   Step %d: Current node = %d, Previous node = %d\n", 
               step, temp->data, temp->prev->data);
        temp = temp->prev;
        step++;
    } while (temp != head->prev);
    printf("   Reached starting point! Circular traversal complete.\n");
}
int main() {
    printf("===============================================================================\n");
    printf("                                                                               \n");
    printf("              DOUBLY CIRCULAR LINKED LIST - COMPLETE IMPLEMENTATION           \n");
    printf("                         WITH STEP-BY-STEP EXPLANATION                        \n");
    printf("                                                                               \n");
    printf("===============================================================================\n");   
    struct Node* head = NULL;
    int choice, data, afterData;
    printf("\nWelcome to the Doubly Circular Linked List Demonstration!\n");
    printf("This program will show you every step of how a Doubly Circular Linked List works.\n");
    do {
        printf("\n-------------------------------------------------------------------------------\n");
        printf("MAIN MENU\n");
        printf("-------------------------------------------------------------------------------\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Node\n");
        printf("4. Delete Node\n");
        printf("5. Display List\n");
        printf("6. Count Nodes\n");
        printf("7. Demonstrate Traversal\n");
        printf("8. Exit\n");
        printf("-------------------------------------------------------------------------------\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                displayList(head);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                displayList(head);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter data of the node after which to insert: ");
                scanf("%d", &afterData);
                head = insertAfter(head, afterData, data);
                displayList(head);
                break;
            case 4:
                printf("Enter data of node to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                displayList(head);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                countNodes(head);
                break;
            case 7:
                demonstrateTraversal(head);
                break;
            case 8:
                printf("\nThank you for using the Doubly Circular Linked List Demo!\n");
                printf("Hope you learned how Doubly Circular Linked Lists work!\n");
                break;                
            default:
                printf("Invalid choice! Please enter a number between 1-8.\n");
        }
    } while (choice != 8);
    if (head != NULL) {
        printf("\nCleaning up: Freeing all remaining nodes...\n");
        struct Node* current = head;
        struct Node* nextNode;
        do {
            nextNode = current->next;
            printf("   Freeing node with data: %d\n", current->data);
            free(current);
            current = nextNode;
        } while (current != head);
    }
    return 0;
}