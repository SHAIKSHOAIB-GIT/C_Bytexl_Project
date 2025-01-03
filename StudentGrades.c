#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[100];
    float grade;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void addStudent(int id, const char *name, float grade) {
    if (student_count < MAX_STUDENTS) {
        students[student_count].id = id;
        strcpy(students[student_count].name, name);
        students[student_count].grade = grade;
        student_count++;
        printf("Student added successfully.\n");
    } else {
        printf("Student list is full. Cannot add more students.\n");
    }
}

void deleteStudent(int id) {
    int found = 0;
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void updateGrade(int id, float new_grade) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            students[i].grade = new_grade;
            printf("Grade updated successfully.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void displayStudents() {
    if (student_count == 0) {
        printf("No students in the list.\n");
    } else {
        for (int i = 0; i < student_count; i++) {
            printf("ID: %d, Name: %s, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
        }
    }
}

int main() {
    int choice, id;
    char name[100];
    float grade;

    while (1) {
        printf("\nStudent Grade Management System\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Grade\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &id);
                printf("Enter student name: ");
                scanf(" %[^\n]%*c", name);  // To read a string with spaces
                printf("Enter student grade: ");
                scanf("%f", &grade);
                addStudent(id, name, grade);
                break;
            case 2:
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(id);
                break;
            case 3:
                printf("Enter student ID to update grade: ");
                scanf("%d", &id);
                printf("Enter new grade: ");
                scanf("%f", &grade);
                updateGrade(id, grade);
                break;
            case 4:
                displayStudents();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
