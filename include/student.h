#ifndef STUDENT_H

#define STUDENT_H

#define NAME_LEN 64
#define MAJOR_LEN 32

typedef struct
{
	char name[NAME_LEN];
	char major[MAJOR_LEN];
	int id;
	int age;
	int yearLvl;
	float gpa;
} Student;

Student student_create(const char* name, const char* major, float gpa, int yearLvl, int age);
void student_print(const Student* s);
int student_validate(const Student* s);

#endif
