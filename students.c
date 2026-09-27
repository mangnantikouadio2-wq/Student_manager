#include <stdio.h>
#include <string.h>
#include "student.h"

static void copy_name(char destination[], const char source[]) {
    strncpy(destination, source, 49);
    destination[49] = '\0';
}

int add_student(student *array, char *new_name) {
    if (student_count >= MAX_STUDENTS) {
        return 0;
    }
    student new_student;
    copy_name(new_student.name, new_name);
    new_student.ratings_number = 0;
    new_student.average = 0;
    array[student_count] = new_student;
    student_count++;
    return 1;
}

int find_student_index(student *array, char *student_name) {
    int i = 0;
    while(i < student_count && strcmp(student_name, array[i].name) != 0) {
        i++;
    }
    if (i == student_count) {
        return -1;
    }
    else {
        return i;
    }
}

int remove_student(student *array, char *name_to_remove) {
    int i = find_student_index(array, name_to_remove);
    if (i == -1) {
        return 0;
    }
    for (int j=i; j < student_count - 1; j++) {
        array[j] = array[j+1];
    }
    student_count--;
    return 1;
}

void update_student_name(student *s, char *new_name) {
    copy_name(s->name, new_name);
}

int add_mark_to_student(student *s, float new_mark) {
    if (s->ratings_number >=MAX_MARKS) {
        return 0;
    }
    s->marks[s->ratings_number] = new_mark;
    s->ratings_number++;
    update_average(s);
    return 1;
}

int update_single_mark(student *s, int mark_index, float new_mark) {
    if (mark_index < 0 || mark_index >= s->ratings_number) {
        return 0;
    }
    s->marks[mark_index] = new_mark;
    update_average(s);
    return 1;
}

void update_average(student *s) {
    if (s->ratings_number == 0) {
        s->average = 0;
        return;
    }
    float sum = 0;
    for (int i = 0; i < s->ratings_number; i++) {
        sum+= s->marks[i];
    }
    s->average = sum / s->ratings_number;
}