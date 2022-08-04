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
    students[0] = (Student){2.3, 100, "Ivan", 25};
    students[1] = (Student){4.8, 145, "Pesho", 18};
    students[2] = (Student){6.0, 132, "Gosho", 30};
    students[3] = (Student){3.7, 265, "Tosho", 21};
    students[4] = (Student){3.0, 37, "Petko", 28};

    FILE *file = fopen("binary_struct", "wb");

    fwrite(students, sizeof(Student), 5, file);
    fclose(file);

    return 0;
}