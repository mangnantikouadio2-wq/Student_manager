#include <stdio.h>
#include <string.h>

extern int student_count;

typedef struct {
    char name[50];
    float marks[5];
    int ratings_number;
    float average;
} student;

student *add_student(student *array, char *new_name, int ratings_number) {
    student new_student;
    strcpy(new_student.name, new_name);
    new_student.ratings_number = ratings_number;
    new_student.average = 0;
    array[student_count] = new_student;
    student_count++;
    return array;
}

int find_student_index(student *array, char *student_name) {
    int i = 0;
    while(strcmp(student_name, array[i].name) != 0 && i < student_count) {
        i++;
    }
    return i;
}

student *remove_student(student *array, char *name_to_remove) {
    int i = find_student_index(array, name_to_remove);
    for (int j=i; j < student_count; j++) {
        array[j] = array[j+1];
    }
    student_count --;
    return array;
}

void update_student_name(student *s, char *new_name) {
    strcpy(s->name, new_name);
}

int add_mark_to_student(student *s, float new_mark) {
    if (s->ratings_number >=5) {
        return 0;
    }
    s->marks[s->ratings_number] = new_mark;
    s->ratings_number++;
    return 1;
}

int update_single_mark(student *s, int mark_index, float new_mark) {
    if (mark_index < 0 || mark_index > s->ratings_number) {
        return 0;
    }
    s->marks[mark_index] = new_mark;
    return 1;
}