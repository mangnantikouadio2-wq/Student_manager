#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 50
#define BY_NAME 0
#define BY_AVERAGE 1

typedef struct {
    char name[50];
    float marks[5];
    int ratings_number;
    float average;
} student;

extern int student_count;

student *add_student(student *array, char *new_name);
int find_student_index(student *array, char *student_name);
int remove_student(student *array, char *name_to_remove);
void update_student_name(student *s, char *new_name);
int add_mark_to_student(student *s, float new_mark);
int update_single_mark(student *s, int mark_index, float new_mark);
void update_average(student *s);

#endif