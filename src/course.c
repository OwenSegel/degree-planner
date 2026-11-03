#include "course.h"

course_t *find_course(course_t course_list[], int num_courses, const char *name) {
	return &course_list[0];
}

int link_prereqs(course_t course_list[], int num_courses) {
	return 0;
}

void print_course(const course_t course) {
  printf("%s: %d Credits\nPrerequisites:\n", course.name, course.credits);

  for (int i = 0; i < MAX_PREREQS; i++) {
    if (course.prerequisite[i] != NULL) {
      printf("%d. %s\n", i + 1, course.prerequisite[i]->name);
    }
    else break;
  }
}
