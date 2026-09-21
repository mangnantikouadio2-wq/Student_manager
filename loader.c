#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <student.h>


int save_to_csv(const char *file_name, student *array, int count) {
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        return 0;
    }
    for (int i= 0; i < count; i++) {
        fprintf(fp, "%s,", array[i].name);
        for (int k=0; k < 5; k++) {
            fprintf(fp, "%.2f,", array[i].marks[k]);
        }
        fprintf(fp, "%.2f\n", array[i].average);
    }
    fclose(fp);
    return 1;
}

int load_from_csv(const char *file_name, student *array) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        return 0;
    }
    char line[100];
    int loaded_count = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        char name[50];
        float n1, n2, n3, n4, n5, avg;
        sscanf(line, "%49[^,], %f, %f, %f, %f, %f, %f,",
                name,
                &n1, &n2, &n3, &n4, &n5,
                &avg);
        strcpy(array[loaded_count].name, name);
        array[loaded_count].marks[0] = n1;
        array[loaded_count].marks[1] = n2;
        array[loaded_count].marks[2] = n3;
        array[loaded_count].marks[3] = n4;
        array[loaded_count].marks[4] = n5;
        array[loaded_count].average = avg;
        loaded_count++;   
    }
    fclose(fp);
    return loaded_count;
}