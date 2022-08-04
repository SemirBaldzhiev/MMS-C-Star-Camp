#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    double grade;
    unsigned int courses_taken;
    char name[7];
    unsigned char age;
} Student;



int main() {
    Student students[5];
    
    FILE *file = fopen("binary_struct", "rb");

    fread(students, sizeof(Student), 5, file);

    for (int i = 0; i < 5; i++){
        printf("%lf %d %s %d", students[i].grade, students[i].courses_taken, students[i].name, students[i].age);
    }
    fclose(file);

    return 0;
}