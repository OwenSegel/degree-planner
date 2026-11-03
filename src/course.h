#ifndef COURSE_H
#define COURSE_H

#define LINK_ERR (-1)

#define MAX_NAME_LEN (64)
#define MAX_PREREQS (5)
#define MAX_CLASSES (10)
#define MAX_CREDITS (18)

typedef struct course {
  char name[MAX_NAME_LEN];
  int credits;
  int num_prereqs;
  char prerequisite_name[MAX_PREREQS][MAX_NAME_LEN];
  struct course *prerequisite[MAX_PREREQS];
} course_t;

typedef struct semester {
  course_t *course_list[MAX_CLASSES];
  int num_courses;
} semester_t;

course_t *find_course(course_t *course_list, int num_courses, const char *name);
int link_prereqs(course_t *course_list, int num_courses);
void print_course(const course_t course);

#endif