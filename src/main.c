#include "course.h"
#include "parse.h"
#include "check.h"

#include <stdio.h>

int main(int argc, char **argv) {

  if (argc != 3) {
    printf("Usage: ./planner course_list.txt semester_plan.txt\n");
    return 1;
  }

  FILE *course_file = fopen(argv[1], "r");
  if (course_file == NULL) {
    printf("Course file not opened\n");
    return 1;
  }
  
  FILE *plan_file = fopen(argv[2], "r");
  if (plan_file == NULL) {
    printf("Plan file not opened\n");
    fclose(course_file);
    course_file = NULL;
    return 1;
  }

  int num_courses   = count_courses(course_file);
  int num_semesters = count_semesters(plan_file);
  course_t courses[num_courses] = {};
  semester_t plan[num_semesters] = {};

  if (read_courses(course_file, courses, num_courses) != OK) {
    printf("Course file invalid\n");
    return 1;
  }
  if (read_plan(plan_file, courses, num_courses, plan, num_semesters) != OK) {
    printf("Plan file invalid\n");
    return 1;
  }

  fclose(course_file);
  fclose(plan_file);
  course_file = NULL;
  plan_file = NULL;

  if (link_prereqs(courses, num_courses) != OK) {
    printf("Linking error\n");
    return 1;
  }

  print_report(plan, num_semesters);
}
