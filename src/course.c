#include "course.h"
#include "parse.h"

#include <string.h>
#include <stdio.h>

course_t *find_course(course_t course_list[], int num_courses, const char *name) {

  for (int i = 0; i < num_courses; i++) {
    if (strncmp(course_list[i].name, name, MAX_NAME_LEN) == 0) {
      return &course_list[i];
    }
  }

  return NULL;
}

int link_prereqs(course_t course_list[], int num_courses) {

  for (int i = 0; i < num_courses; i++) {
    for (int x = 0; x < course_list[i].num_prereqs; x++) {
      course_t *course = find_course(course_list, num_courses, course_list[i].prerequisite_name[x]);
      if (course == NULL) {
        return LINK_ERR;
      }
      course_list[i].prerequisite[x] = course;
    }
  }

  return OK;
}

void print_course(const course_t course) {

  printf("%s: %d Credits\n", course.name, course.credits);

  if (course.num_prereqs != 0) {
    printf("Prerequisites:\n");
  }
  for (int i = 0; i < course.num_prereqs; i++) {
    printf("%d. %s\n", i + 1, course.prerequisite_name[i]);
  }
}