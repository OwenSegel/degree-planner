#include "course.h"
#include "parse.h"

#include <stdio.h>
#include <string.h>

int count_lines(FILE *fp) {
  int line_count = 0;

  int c = fgetc(fp);
  while (c != EOF) {
    if (c == '\n') line_count++;
    c = fgetc(fp);
  }
  rewind(fp);

  return line_count;
}

int count_courses(FILE *fp) {
  return count_lines(fp);
}

int count_semesters(FILE *fp) {
  return count_lines(fp);
}

// cname|credits|prereq_name1/prereq_name2/.../prereq_nameN|
int read_courses(FILE *fp, course_t courses[], int num_courses) {
  
  char name[MAX_NAME_LEN] = "";
  int credits = 0;
  char prereq_name[MAX_NAME_LEN] = "";
  char pipes[2] = "";
  
  for (int i = 0; i < num_courses; i++) {

    if (fscanf(fp, "%31[^|]%c%d%c", name, &pipes[0], &credits, &pipes[1]) != 4) return BAD_RECORD;

    for (int x = 0; x < MAX_PREREQS; x++) {
      if (fscanf(fp, "%31[^|/]%c", prereq_name, &pipes[0]) != 2) {
        if (x == 0) {
          if (fgetc(fp) != '|') return BAD_RECORD;
          courses[i].num_prereqs = x;
          break;
        }
        else return BAD_RECORD;
      }
      strcpy(courses[i].prerequisite_name[x], prereq_name);
      if (pipes[0] == '|') {
        courses[i].num_prereqs = x + 1;
        break;
      }
      else if (pipes[0] != '/') return BAD_RECORD;
    }

    strcpy(courses[i].name, name);
    courses[i].credits = credits;

    if (fgetc(fp) != '\n') return BAD_RECORD;
  }

  return OK;
}

// course_name1/course_name_2/.../course_nameN|
int read_plan(FILE *fp, course_t courses[], int num_courses, semester_t semesters[], int num_semesters) {
  return OK;
}