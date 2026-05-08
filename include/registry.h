#ifndef REGISTRY_H

#define REGISTRY_H

#include "student.h"

typedef struct
{
	Student* students;
	int count;
	int capacity;
} Registry;

void registry_init(Registry* reg);
int registry_add(Registry* reg, Student s);
int registry_delete_by_id(Registry* reg, int id);
Student* registry_search_by_name(Registry* reg, const char* name);
Student* registry_search_by_id(Registry* reg, int id);
void registry_list(Registry* reg);
void registry_free(Registry* reg);

#endif
