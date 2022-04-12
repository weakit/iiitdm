#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* name;
    int age;
    int rollNo;
    char* address;
} Student;

void assertMemory(void* pointer) {
    if (pointer != NULL) return;
    printf("Unable to allocate memory.");
    exit(1); 
}

int main() {
    // allocate memory
    Student* student = (Student*) malloc(sizeof(Student)); assertMemory(student);
    student->name = (char*) malloc(50 * sizeof(char)); assertMemory(student->name);
    student->address = (char*) malloc(200 * sizeof(char)); assertMemory(student->address);
    
    printf("Enter Name: "); fgets(student->name, 50, stdin);
    printf("Enter Address: "); fgets(student->address, 200, stdin);
    printf("Enter Age: "); scanf("%d", &student->age);
    printf("Enter Roll No: "); scanf("%d", &student->rollNo);

    printf("\n\nYour details are:\n");
    printf("\nName: %s", student->name);
    printf("Roll No: %d", student->rollNo);
    printf("\nAge: %d", student->age);
    printf("\nAddress: %s", student->address);

    return 0;
}
