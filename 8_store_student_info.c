#include <stdio.h>
#include <string.h>


struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Declare an array of structures to store student information
    struct Student students[numStudents];

    // Input student information
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter information for Student %d:\n", i + 1);
        printf("Name: ");
        getchar(); // Consume newline character
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove newline character
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    
    printf("\nStudent Information:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}
