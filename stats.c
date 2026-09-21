#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

static merge_by_name(student *array, int begin, int medium, int end) {
    int left_size = medium - begin + 1;
    int right_size = end - medium;
    student *left = malloc(left_size * sizeof(student));
    student *right = malloc(right_size * sizeof(student));
    for (int i=0; i<left_size; i++) {
        left[i] = array[begin + i];
    }
    for (int j=0; j<right_size; j++) {
        right[j] = array[medium + 1 + j];
    }
    int i = 0, j = 0, k = begin;
    while(i<left_size && j<right_size) {
        if(strcmp(left[i].name, right[j].name) <= 0) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < left_size) {
        array[k] = left[i];
        i++;
        k++;
    }
    while(j < right_size) {
        array[k] = right[j];
        j++;
        k++;
    }
    free (left);
    free (right);
}

static merge_by_average(student *array, int begin, int medium, int end) {
    int left_size = medium - begin + 1;
    int right_size = end - medium;
    student *left = malloc(left_size * sizeof(student));
    student *right = malloc(right_size * sizeof(student));
    for (int i=0; i < left_size; i++) {
        left[i] = array[begin + i];
    }
    for (int j=0; j < right_size; j++) {
        right[j] = array[medium + 1 + j];
    }
    int i = 0, j = 0, k = begin;
    while(i<left_size && j<right_size) {
        if (left[i].average <= right[j].average) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left_size) {
        array[k] = left[i];
        i++;
        k++;
    }
    while (j < right_size) {
        array[k] = right[j];
        j++;
        k++;
    }
    free (left);
    free(right);
    
}

void merge_sort(student *array, int begin, int end, int sort_option) {
    if (begin < end) {
        int medium = begin + (end - begin) / 2;
    
    merge_sort(array, begin, medium, sort_option);
    merge_sort(array, medium + 1, end, sort_option);

    switch (sort_option) {
    case BY_NAME:
        merge_by_name(array, begin, medium, end);
        break;
    
    case BY_AVERAGE:
        merge_by_average(array, begin, medium, end);
        break;
    }
    }
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