#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LEN 50
#define MAJOR_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    char major[MAJOR_LEN];
    float gpa;
    int credits;
} Student;

Student registry[MAX_STUDENTS];
int studentCount = 0;

void addStudent();
void displayAll();
void searchByID();
void searchByGPA();
void searchByMajor();

int main() {
    int choice;

    do {
        printf("\n--- Dr. Santos' Student Registry ---\n");
        printf("1. Add new student\n2. Display all students\n3. Search by ID\n");
        printf("4. Search by GPA\n5. Search by Major\n6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchByID(); break;
            case 4: searchByGPA(); break;
            case 5: searchByMajor(); break;
            case 6: printf("Exiting.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

void addStudent() {
    int numToAdd;
    
    printf("\nHow many students would you like to add? ");
    scanf("%d", &numToAdd);

    if (studentCount + numToAdd > MAX_STUDENTS) {
        printf("Error: Only %d slots remaining.\n", MAX_STUDENTS - studentCount);
        return;
    }

    for (int i = 0; i < numToAdd; i++) {
        printf("\n--- Entering details for student #%d ---\n", i + 1);
        
        printf("ID: ");
        scanf("%d", &registry[studentCount].id);
        
        printf("Name: ");
        scanf(" %[^\n]s", registry[studentCount].name);
        
        printf("Major: ");
        scanf(" %[^\n]s", registry[studentCount].major);
        
        printf("GPA: ");
        scanf("%f", &registry[studentCount].gpa);
        
        printf("Credits: ");
        scanf("%d", &registry[studentCount].credits);

        studentCount++;
        printf("Student saved.\n");
    }
}
void displayAll() {
    
    printf("\n%-6s %-20s %-10s %-6s %-8s\n", "ID", "Name", "Major", "GPA", "Credits");
    printf("------------------------------------------------------------\n");
    
    for(int i = 0; i < studentCount; i++) {
        printf("%-6d %-20s %-10s %-6.2f %-8d\n", 
               registry[i].id, 
               registry[i].name, 
               registry[i].major, 
               registry[i].gpa, 
               registry[i].credits);
    }
}
void searchByID() {
    int id, found = 0;
    printf("Enter Student ID: ");
    scanf("%d", &id);
    for(int i = 0; i < studentCount; i++) {
        if(registry[i].id == id) {
            printf("Found: %s\nMajor: %s\nGPA: %.2f\n", registry[i].name, registry[i].major, registry[i].gpa);
            found = 1;
        }
    }
    if(!found) printf("Student not found.\n");
}

void searchByGPA() {
    float threshold;
    printf("Enter GPA threshold: ");
    scanf("%f", &threshold);
    for(int i = 0; i < studentCount; i++) {
        if(registry[i].gpa >= threshold) 
            printf("- %s (GPA: %.2f)\n", registry[i].name, registry[i].gpa);
    }
}

void searchByMajor() {
    char major[MAJOR_LEN];
    int count = 0;
    printf("Enter Major: ");
    scanf("%s", major);
    for(int i = 0; i < studentCount; i++) {
        if(strcmp(registry[i].major, major) == 0) {
            printf("- %s\n", registry[i].name);
            count++;
        }
    }
    printf("Found %d student(s) in %s.\n", count, major);
}
