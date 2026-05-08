#ifndef STUDENT_H

#define STUDENT_H

typedef struct
{
	char name[64];
	char grade[1];
	char major[32];
	int id;
	int age;
	int yearLvl;
	float gpa;
} Student;

#endif
