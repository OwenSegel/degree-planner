#ifndef CHECK_H
#define CHECK_H

#include "course.h"

int check_prereqs(const semester_t semester[], int num_semesters);
int check_credits(const semester_t semester[], int num_semesters);
void print_report(const semester_t semester[], int num_semesters);

#endif
