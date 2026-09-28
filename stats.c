#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

static int compare_by_name(student a, student b) {
    if (strcmp(a.name, b.name) <=0) {
        return 0;
    } else {
        return 1;
    }
}

static int compare_by_average(student a, student b) {
    if (a.average <= b.average) {
        return 0;
    } else {
        return 1;
    }
}

static void merge(student *array,student *buffer, int begin, int medium, int end, int (*compare)(student, student)) {
    for (int i = begin; i<= end; i++) {
        buffer[i] = array[i];
    }
    int i = begin;
    int j = medium + 1;
    int k = begin;
    while(i <= medium && j <= end ) {
        if (compare(buffer[i], buffer[j]) == 0) {
            array[k++] = buffer[i++];
        } else {
            array[k++] = buffer[j++];
        }
    }
    while(i <= medium) {
        array[k++] = buffer[i++];
    }
}

static void rec_merge_sort(student *array, student *buffer, int begin, int end, int sort_option) {
    if (begin < end) {
        int medium = begin + (end - begin) / 2;
        rec_merge_sort(array, buffer, begin, medium, sort_option);
        rec_merge_sort(array, buffer, medium + 1, end, sort_option);
        switch (sort_option) {
        case BY_NAME:
            merge(array, buffer, begin, medium, end, compare_by_name);
            break;
        case BY_AVERAGE:
            merge(array, buffer, begin, medium, end, compare_by_average);
            break;
        }
    }
}

void merge_sort(student *array, int n, int sort_option) {
    student *buffer = malloc(n * sizeof(student));
    rec_merge_sort(array, buffer, 0, n - 1, sort_option);
    free(buffer);
}

float total_average(student *array) {
    if (array == NULL || student_count <=0) {
        return 0.0f;
    }
    float sum = 0.0f;
    for (int i=0; i < student_count; i++) {
        sum += array[i].average;
    }
    return sum / student_count;
}