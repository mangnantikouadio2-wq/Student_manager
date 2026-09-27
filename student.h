#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_MARKS 5
#define BY_NAME 0
#define BY_AVERAGE 1

typedef struct {
    char name[MAX_NAME_LENGTH];
    float marks[MAX_MARKS];
    int ratings_number;
    float average;
} student;

extern int student_count;

int add_student(student *array, char *new_name);
int find_student_index(student *array, char *student_name);
int remove_student(student *array, char *name_to_remove);
void update_student_name(student *s, char *new_name);
int add_mark_to_student(student *s, float new_mark);
int update_single_mark(student *s, int mark_index, float new_mark);
void update_average(student *s);

void merge_sort(student *array, int begin, int end, int sort_option);
float total_average(student *array);

int save_to_csv(const char *file_name, student *array, int count);
int load_from_csv(const char *file_name, student *array);

#endif