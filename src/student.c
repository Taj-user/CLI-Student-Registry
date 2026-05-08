#include <stdio.h>
#include <string.h>
#include "../include/student.h"

Student student_create(const char* name, const char* major, float gpa, int yearLvl, int age)
{
    Student s;
    s.id = 0;
    s.gpa = gpa;
    s.yearLvl = yearLvl;
    s.age = age;
    strncpy(s.name, name, NAME_LEN - 1);
    strncpy(s.major, major, MAJOR_LEN - 1);
    s.name[NAME_LEN - 1] = '\0';
    s.major[MAJOR_LEN - 1] = '\0';

    return s;
}

int student_validate(const Student* s)
{
    if(s->name[0] == '\n') return 0;
    if(s->major[0] == '\n') return 0;
    if(s->gpa < 0.0f || s->gpa > 4.3f) return 0;
    if(s->yearLvl < 1 || s->yearLvl > 4) return 0;
    if(s->age < 17) return 0;

    return 1;
}

void student_print(const Student* s)
{
    printf("-------------------------\n");
    printf("ID      : %d\n", s->id);
    printf("Name    : %s\n", s->name);
    printf("Age     : %d\n", s->age);
    printf("Major   : %s\n", s->major);
    printf("GPA     : %.1f\n", s->gpa);
    printf("Year     : %d\b", s->yearLvl);
    printf("-------------------------\n");
}