#include "dorm.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
struct dorm_t create_dorm ( char *_name, unsigned short _capacity, enum gender_t _gender )
{
    struct dorm_t dorm_;
    dorm_.residents_num = 0;
    strcpy( dorm_.name, _name );
    dorm_.capacity = _capacity;
    dorm_.gender   = _gender;

    return dorm_;
}

void print_dorm_detail ( struct dorm_t dorm )
{
    printf( "%s|%d|", dorm.name, dorm.capacity );
    if (dorm.gender==GENDER_FEMALE){
        printf("female|%d\n", dorm.residents_num);
    } else {
        printf("male|%d\n", dorm.residents_num);
    }

   fflush( stdout ); 
    
}

void print_dorm(struct dorm_t dorm){
    printf("%s|%d|", dorm.name, dorm.capacity);
    if (dorm.gender==GENDER_FEMALE){
        printf("female\n");
    } else {
        printf("male\n");
    }

    fflush(stdout);
}