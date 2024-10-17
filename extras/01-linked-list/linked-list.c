#include <stdio.h>
#include <stdlib.h>

// Consider putting LinkedList as a module
// i.e. (.h and .c)

// Define a node structure
typedef struct Node {
    void* data;
    struct Node* next;
} Node;

// Function pointer type for printing data
typedef void (*PrintFunc)(void*);

// Function to create a new node
Node* createNode(void* data) {
    Node* newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(Node** headRef, void* newData) {
    Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Generic function to print the linked list using a function pointer
void printList(Node* node, PrintFunc printFunc) {
    while (node != NULL) {
        printFunc(node->data);  // Call the function pointer to print the data
        node = node->next;
    }
    printf("NULL\n");
}

// Specific print function for integers
void printInt(void* data) {
    printf("%d -> ", *(int*)data);
}

// Specific print function for floats
void printFloat(void* data) {
    printf("%.2f -> ", *(float*)data);
}

// My custom struct
typedef struct {
	int age;
	char name[20];
} Person;

// Specific print function for Person
void printPerson(void* data) {
	Person* person = (Person*)data;  // Cast the void pointer to a Person pointer
    printf("name: %s, age: %d -> ", person->name, person->age);
}

// Main function
int main() {
    Node* head = NULL;

    // Example with integers
    int intData1 = 10;
    int intData2 = 20;
    push(&head, &intData1);
    push(&head, &intData2);

    printf("Integer Linked List:\n");
    printList(head, printInt);  // Pass the printInt function as a parameter

    // Example with floats
    Node* floatHead = NULL;
    float floatData1 = 3.14;
    float floatData2 = 2.71;
    push(&floatHead, &floatData1);
    push(&floatHead, &floatData2);

    printf("Float Linked List:\n");
    printList(floatHead, printFloat);  // Pass the printFloat function as a parameter

	// Example with custom struct
    Node* personHead = NULL;
	Person personData1 = { 30, "John" };
    Person personData2 = { 28, "Jane" };
    push(&personHead, &personData1);
    push(&personHead, &personData2);

    printf("Person Linked List:\n");
    printList(personHead, printPerson);  // Pass the printPerson function as a parameter

    return 0;
}
