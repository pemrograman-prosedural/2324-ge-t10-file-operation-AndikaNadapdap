// 12S23013 - Andika Nadapdap
// 12S23036 - Jopel Simarmata

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"
#include <string.h>
#include <stdlib.h>

int main(int _argc, char **_argv)
{
    int total_dorms = 0;
    int total_students = 0;
    struct dorm_t *dorms = malloc(10 * sizeof(struct dorm_t)); 
    struct student_t *students = malloc(20 * sizeof(struct student_t));
    FILE *file;
    char buffer[200];


    file = fopen("./storage/dorm-repository.txt", "r");
    while (fgets(buffer, 200, file) != NULL)
    {
        buffer[strcspn(buffer, "\r\n")] = 0;
        char *token = strtok(buffer, "|");
        char  *name = token;
        token = strtok(NULL, "|");
        short unsigned capacity = atoi(token);
        token = strtok(NULL, "|");
        if (strcmp(token,"male\n")==0){
            dorms[total_dorms]=create_dorm(name, capacity, GENDER_MALE);
            total_dorms++;
        } else {
            dorms[total_dorms]=create_dorm(name, capacity, GENDER_FEMALE);
            total_dorms++;
        }

    }

    file = fopen("./storage/student-repository.txt", "r");
    while (fgets(buffer, 200, file) != NULL)
    {
        buffer[strcspn(buffer, "\r\n")] = 0;
        char *token = strtok(buffer, "|");
        char  *id = token;
        token = strtok(NULL, "|");
        char *name = token;
        token = strtok(NULL, "|");
        char *year = token;
        token = strtok(NULL, "|");
        if  (strcmp(token,"male\n")==0){
            students[total_students]=create_student(id, name, year,GENDER_MALE);
            total_students++;
        } else {
            students[total_students]=create_student(id, name, year,GENDER_FEMALE);
            total_students++;
        }
    }

    fclose(file);


    char perintah[60];
    while(1){
        perintah[0]='\0';
        fgets(perintah, 60, stdin);
        fflush(stdin);
        {
            int len = strlen(perintah);
            for (short a = 0; a< len; a++){
                if(perintah[a]=='\r' || perintah[a]=='\n'){
                    for(short b = a; b < len; b++){
                        perintah[b] = perintah[b+1];
                        len--;
                        a--;
                    }
                }
            }
        }
        if (strcmp(perintah, "dorm-print-all-detail")==0){
            for (int i = 0; i < total_dorms; i++)
            {
                print_dorm_detail(dorms[i]);
            }
        } else if (strcmp(perintah,"student-print-all-detail")==0){
            for (int i = 0; i < total_students; i++)
            {
                print_student_detail(students[i]);
            }
        } else if (strcmp(perintah,"student-print-all")==0){
            for (int i = 0; i < total_students; i++)
            {
                print_student(students[i]);
            }

        } else if (strcmp(perintah,"dorm-print-all")==0){
            for (int i = 0; i < total_dorms; i++)
            {
                print_dorm(dorms[i]);
            }
        } else if (strcmp(perintah,"---")==0){
            break;
        }
        char *token = strtok(perintah, "#");
        if (strcmp(token,"student-add")==0){
            token = strtok(NULL, "#");
            char *id = token;
            token = strtok(NULL, "#");
            char *name = token;
            token = strtok(NULL, "#");
            char *year = token;
            token = strtok(NULL, "#");
            if (strcmp(token,"male\n")==0){
                students[total_students]=create_student(id, name, year,GENDER_MALE);
                total_students++;
            } else {
                students[total_students]=create_student(id, name, year, GENDER_FEMALE);
                total_students++;
            }
        } else if (strcmp(token,"dorm-add")==0){
            token = strtok(NULL, "#");
            char *name = token;
            token = strtok(NULL, "#");
            short unsigned capacity = atoi(token);
            token = strtok(NULL, "#");
            if (strcmp(token,"male\n")==0){
                dorms[total_dorms]=create_dorm(name, capacity,GENDER_MALE);
                total_dorms++;
            } else {
                dorms[total_dorms]=create_dorm(name, capacity, GENDER_FEMALE);
                total_dorms++;
            }    
        }
    }
    free(dorms);
    free(students);
    return 0;
}
