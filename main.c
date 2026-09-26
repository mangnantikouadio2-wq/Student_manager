#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "student.h"


int main(void) {
    student strudent_array[MAX_STUDENTS];
    student_count = load_from_csv("student.csv", strudent_array);
    
    bool runnig = true;
    int choice = 0;

    printf("=====  STUDENT MANAGER  =====\n");
    while (runnig) {
        printf("What do you want to do?\n");
        printf("1 - Add a student\n");
        printf("2 - Modifie a student's initials\n");
        printf("3 - Add a mark\n");
        printf("4 - Remove a student\n");
        printf("5 - Sort the list\n");
        printf("6 - Display the class average\n");
        printf("7 - Save and exit\n");
        printf("Your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n') {
                continue;
            }
        }
        switch (choice) {
            case 1:
                char brand_new_name[50];
                printf("Enter the student's name: ");
                scanf("%49[^\n]", brand_new_name);
                if (add_student(strudent_array, brand_new_name)) {
                    break;
                } else {
                    printf("The maximum number of student is reached!\n");
                    break;
                }
            case 2:
                char target_name[50];
                char new_name[50];
                printf("What student's name do you want to modifie?\n");
                scanf("%49[^\n]", target_name);
                int index = find_student_index(strudent_array, target_name);
                if (index == -1) {
                    printf("Student not found!\n");
                    break;
                } else {
                    printf("Enter the new student's name\n");
                    scanf("%49[^\n]", new_name);
                    update_student_name(strudent_array[index].name, new_name);
                    break;
                }
            case 3:
                char mark_targer_name[50];
                float new_mark;
                printf("What student do you want to add a mark to?\n");
                scanf("%49[^\n]", mark_targer_name);
                int mark_index =find_student_index(strudent_array, mark_targer_name);
                if(mark_index == -1) {
                    printf("Student not found\n");
                    break;
                } else {
                    printf("Enter the new mark: ");
                    scanf("%f", &new_mark);
                    if (new_mark < 0.0f || new_mark > 20.0f) {
                        printf("The mark must be out of 20!\n");
                        break;
                    } else if (add_mark_to_student(&strudent_array[mark_index], new_mark)) {
                        break;
                    } else {
                        printf("The maximum ratings number supported is reached\n");
                        break;
                    }
                    
                }
            case 4:
                char name_to_remove[50];
                printf("What student do you want to remove?\n");
                scanf("%49[^\n]", name_to_remove);
                if (remove_student(strudent_array, name_to_remove)) {
                    break;
                } else {
                    printf("Student not found\n");
                    break;
                }
            case 5:
                if (student_count == 0) {
                    print("There is no student yet, you can't sort sort nothing!\n");
                    break;
                }
                int sort_option = 0;
                printf("Do you want to sort the list:\n");
                printf("1 - By name?\n");
                printf("2 - By average?\n");
                if (scanf("%d", &sort_option) != 1) {
                    while (getchar() != "\n") {
                        continue;
                    }
                }
                switch (sort_option) {
                    case 1:
                        merge_sort(strudent_array, 0, student_count-1, BY_NAME);
                        break;
                    case 2:
                        merge_sort(strudent_array, 0, student_count-1, BY_AVERAGE);
                        break;
                    default:
                        printf("Invalide choice\n");
                        break;
                }
                break;
            case 6:
                if(student_count == 0) {
                    printf("%f... No student found btw\n", total_average(strudent_array));
                    break;
                } else {
                    printf("The average of the class is: %f\n", total_average(strudent_array));
                    break;
                }
            case 7: //my nightmare 
        }
    }
    
}