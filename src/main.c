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
  FILE *plan_file = fopen(argv[2], "r");

  int num_courses   = count_courses(course_file);
  int num_semesters = count_semesters(plan_file);
  course_t courses[num_courses] = {};
  semester_t plan[num_semesters] = {};

  read_courses(course_file, courses, num_courses);
  read_plan(plan_file, courses, num_courses, plan, num_semesters);

  fclose(course_file);
  fclose(plan_file);
  course_file = NULL;
  plan_file = NULL;

  link_prereqs(courses, num_courses);

  check_prereqs(plan, num_semesters);
  check_credits(plan, num_semesters);
  // print_report(plan, num_semesters);
}
