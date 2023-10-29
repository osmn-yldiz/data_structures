#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define a structure for a linked list node
struct Node {
    struct Node* next;
    int data;
};
typedef struct nodes node;

// Define a structure for a student
struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
};
typedef struct students student;

// Function to display the linked list
void listShow(struct Node* head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

// Function to create a linked list with random numbers
struct Node* addRandom(struct Node* head) {
    srand(time(NULL));
    head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temphead = head;
    int i1, i2, i3;
    for (i1 = 0; i1 < 100; i1++) {
        temphead->data = rand();
        if (i1 == 99) {
            temphead->next = NULL;
        } else {
            temphead->next = (struct Node*)malloc(sizeof(struct Node));
            temphead = temphead->next;
        }
    }
    temphead = head;
    for (i1 = 0; i1 < 99; i1++) {
        for (i2 = 0; i2 + i1 < 99; i2++) {
            if (temphead->data < temphead->next->data) {
                struct Node* temp;
                temp = temphead->next;
                temphead->next = temphead->next->next;
                temp->next = temphead;
                if (i2 == 0) {
                    head = temp;
                } else {
                    struct Node* temp2 = head;
                    for (i3 = 0; i3 < i2 - 1; i3++)
                        temp2 = temp2->next;
                    temp2->next = temp;
                }
            }
            temphead = temphead->next;
        }
        temphead = head;
    }
    return head;
}

// Function to create a linked list with even and odd numbers
struct Node* addEvenOdd(struct Node* head) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    getInfo(temp);
    while (temp->data != -1) {
        if (head == NULL) {
            temp->next = NULL;
            head = temp;
        } else if (temp->data % 2 != 0) {
            temp->next = head;
            head = temp;
        } else {
            temp->next = NULL;
            struct Node* temphead = head;
            while (temphead->next != NULL)
                temphead = temphead->next;
            temphead->next = temp;
        }
        temp = (struct Node*)malloc(sizeof(struct Node));
        getInfo(temp);
    }
    free(temp);
    return head;
}

// Function to get data from the user
void getInfo(struct Node* temp) {
    printf("Please enter data: ");
    scanf("%d", &temp->data);
}

// Function to create a linked list of students
struct Student* listCreate3(struct Student* head2) {
    int numberOfStudents, i;
    struct Student* temphead;
    printf("Please enter the number of students: ");
    scanf("%d", &numberOfStudents);
    for (i = 0; i < numberOfStudents; i++) {
        if (head2 == NULL) {
            head2 = (struct Student*)malloc(sizeof(struct Student));
            getInfo3(head2);
            head2->next = NULL;
            temphead = head2;
        } else {
            temphead->next = (struct Student*)malloc(sizeof(struct Student));
            temphead = temphead->next;
            getInfo3(temphead);
            temphead->next = NULL;
        }
    }
    return head2;
}

// Function to display the linked list of students
void listShow3(struct Student* node) {
    int i = 1;
    while (node != NULL) {
        printf("%d - %s %d %d\n", i++, node->name, node->age, node->number);
        node = node->next;
    }
}

// Function to get student information from the user
void getInfo3(struct Student* temp) {
    printf("Enter name: ");
    fflush(stdin);
    scanf("%s", temp->name);
    printf("Enter age: ");
    scanf("%d", &temp->age);
    printf("Enter student number: ");
    scanf("%d", &temp->number);
}

// Function to search for a student by name
void ogrenciAra(struct Student* head2, char aranan[]) {
    while (head2 != NULL && strcmp(head2->name, aranan) != 0)
        head2 = head2->next;
    if (head2 == NULL)
        printf("The name you are looking for is not on the list\n");
    else {
        printf("%s %d %d\n", head2->name, head2->age, head2->number);
    }
}

// Function to delete the next node of a student with a given name
void dellNext(struct Student* head2, char aranan[]) {
    while (head2 != NULL && strcmp(head2->name, aranan) != 0)
        head2 = head2->next;
    if (head2 == NULL)
        printf("The name you are looking for is not on the list\n");
    else if (head2->next == NULL)
        printf("Next node is null\n");
    else {
        struct Student* willDell;
        willDell = head2->next;
        head2->next = willDell->next;
        free(willDell);
    }
}

int main() {
    struct Node* head = NULL;
    struct Student* head2 = NULL;
    char c;
    char aranan[30];

    // Code to add students to the linked list (addStudent function missing)
    // ...

    printf("Select an option (1, 2, 3, 4, 5, or 6): ");
    c = getchar();
    
    switch (c) {
        case '1':
            head = addEvenOdd(head);
            listShow(head);
            break;
        case '2':
            head = addRandom(head);
            listShow(head);
            break;
        case '3':
            head2 = listCreate3(head2);
            listShow3(head2);
            break;
        case '4':
            head2 = listCreate3(head2);
            fflush(stdin);
            gets(aranan);
            ogrenciAra(head2, aranan);
            break;
        case '5':
            head2 = listCreate3(head2);
            fflush(stdin);
            gets(aranan);
            dellNext(head2, aranan);
            listShow3(head2);
            break;
        case '6':
            break;
        default:
            printf("Invalid selection!");
            break;
    }

    return 0;
}
