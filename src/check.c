#include "course.h"

#include <stdio.h>

int contains_class(const semester_t semester[], const course_t *course, int last_sem) {

  for (int i = 0; i < last_sem; i++) {
    for (int x = 0; x < semester[i].num_courses; x++) {
      if (semester[i].course_list[x] == course) return 1;
    }
  }

  return 0;
}

int check_prereqs(const semester_t semester[], int num_semesters) {

  int errors = 0;

  for (int i = 0; i < num_semesters; i++) {
    int sem_err = 0;
    for (int x = 0; x < semester[i].num_courses; x++) {
      for (int z = 0; z < semester[i].course_list[x]->num_prereqs; z++) {
        if (!contains_class(semester, semester[i].course_list[x]->prerequisite[z], i)) {
          if (sem_err == 0) {
            printf("Semester #%d\n", x + 1);
            sem_err = 1;
          }
          if (errors == 0) {
            printf("Prerequisite Errors:\n");
          }
          printf("Prerequisites not fulfilled for ");
          print_course(*semester[i].course_list[x]);
          printf("\n");
          errors++;
          break;
        }
      }
    }
  }

  return errors;
}

int check_credits(const semester_t semester[], int num_semesters) {

  int errors = 0;

  for (int i = 0; i < num_semesters; i++) {
    int credits = 0;
    for (int x = 0; x < semester[i].num_courses; x++) {
      credits += semester[i].course_list[x]->credits;
    }
    if (credits > MAX_CREDITS) {
      if (errors == 0) {
        printf("Credit Errors:\n");
      }
      printf("Semester #%d: CREDIT LIMIT EXCEEDED. FOUND %d CREDITS\n", i + 1, credits);
      errors++;
    }
  }
  if (errors != 0) printf("\n");

  return errors;
}

void print_report(const semester_t semester[], int num_semesters) {

}
