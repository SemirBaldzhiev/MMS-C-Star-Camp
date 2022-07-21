#include <stdio.h>

typedef struct  {
    char name[11];
    double x;
    double y;
} point_t;

//typedef struct Point point_t;


void printPoint(point_t p){
    printf("%s(x = %.1lf, y = %.1lf)\n", p.name, p.x, p.y);
}

typedef struct {
    char title[100];
    char author[100];
    int pages;
    double price;
} book_t;

typedef struct {
    point_t point[2];
    char name[100];
    double len;
} line_t;

int main() { 

    point_t p3 = {.name = "A", .x = 4.5, .y = 5.7};
    point_t *p = &p3;
    p->x = 12.4;
    p->y = 12.2;
    //struct Point p2 = {"C", 3.5, 6.7};
    // struct Point p1;

    // p1.x = 256.3;
    // p1.y = 34.2;
    // p1.name
    line_t line = {.point = p3, .name = "dsadas", .len = 12.2};

    book_t book = {.author = "dsa", .title = "sasa", .pages = 12, .price = 2.1};
    printPoint(p3);
    printf("%lu\n",sizeof(book));
    printf("%lu\n",sizeof(p3));
    printf("%lu\n",sizeof(line));

    return 0;
}