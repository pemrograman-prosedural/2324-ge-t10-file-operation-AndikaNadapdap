#include "student.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender)
{
    struct student_t student;
    
    strcpy(student.id, _id);
    strcpy(student.name, _name);
    strcpy(student.year, _year);
    student.gender= _gender;

    return student;
}

void print_student_detail(struct student_t student){
    
    printf("%s|%s|%s|", student.id, student.name, student.year);
            switch ( student.gender ) {
            case GENDER_MALE:
                ( student.dorm != NULL ) ?
                    printf("male|%s\n", student.dorm->name) : printf("male|unassigned\n");
                break;
            
            case GENDER_FEMALE:
                ( student.dorm != NULL ) ?
                    printf("female|%s\n", student.dorm->name) : printf("female|unassigned\n");
                break;
        }



}

void print_student(struct student_t student){
    printf("%s|%s|%s|", student.id, student.name, student.year);
    if (student.gender==GENDER_FEMALE){
        printf("female\n");
    } else {
        printf("male\n");
    }

}