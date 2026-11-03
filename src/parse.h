#ifndef PARSE_H
#define PARSE_H

#include "course.h"

#include <stdio.h>

#define MAX_COURSES (10000)

// ERROR CODES
#define OK            ( 0)
#define BAD_RECORD    (-1)
#define TOO_MUCH_DATA (-2)
#define NO_RECORDS    (-3)
#define FILE_ERR      (-4)

int count_courses(FILE *fp);
int count_semesters(FILE *fp);

int read_courses(FILE *fp, course_t courses[], int num_courses);
int read_plan(FILE *fp, course_t courses[], int num_courses, semester_t semesters[], int num_semesters);

#endif